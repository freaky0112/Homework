//
//  main.cpp
//  Level Order Traversal
//
//  Created by JU YE on 16/3/14.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>

using namespace std;


void swap(int* a,int* b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

struct traversal{
    int* list;
    int length;
};

struct Node{
    int key=-1;
    bool visited=true;
    int* neighbors;
    int length=0;
};

Node *queue;
int length,head,tail,N;

void print_list(traversal* list){
    int i;
    for (i=0; i<list->length-1; i++) {
        cout<<list->list[i]<<" ";
    }
    cout<<list->list[i]<<endl;
}


void Enqueue(Node* node){
    tail=(tail+1)%N;
    queue[tail]=*node;
    length++;
}

Node* dequeue(){
    if (length>0) {
        Node* node=&queue[head];
        length--;
        head=(head+1)%N;
        return node;
    }
    
    return NULL;
}

int pop(Node* node){
    node->length--;
    int postion=0;
    int son=postion*2+1;
    int result=node->neighbors[postion];
    node->neighbors[postion]=node->neighbors[node->length];
    while (son<node->length) {
        if (son-1<node->length&&node->neighbors[son]>node->neighbors[son+1]) {
            son++;
        }
        if (node->neighbors[postion]<node->neighbors[son]) {
            break;
        }
        else{
            swap(&node->neighbors[son], &node->neighbors[postion]);
            postion=son;
            son=postion*2+1;
        }
    }
    return result;
}

void push(Node* node,int neighbor){
    int postion=node->length;
    node->length++;
    node->neighbors[postion]=neighbor;
    while (postion>0) {
        int father=(postion+1)/2-1;
        if (neighbor>node->neighbors[father]) {
            break;
        }else{
            node->neighbors[postion]=node->neighbors[father];
            node->neighbors[father]=neighbor;
            postion=father;
        }
    }
}

traversal* read_data(){
    int R;
    cin>>N>>R;
    traversal* result=new traversal;
    result->length=N;
    result->list=new int[N];
    Node *list=new Node[N];
    for (int i=0; i<N-1; i++) {
        int u,v;
        cin>>u>>v;
        if (list[u-1].key==-1) {
            list[u-1].key=u;
            list[u-1].neighbors=new int[N-1];
        }
        if (list[v-1].key==-1) {
            list[v-1].key=v;
            list[v-1].neighbors=new int[N-1];
        }
        push(&list[u-1], v-1);
        push(&list[v-1], u-1);
    }
    
//    for (int i=0; i<list[4].length; i++) {
//        cout<<list[4].neighbors[i]<<" ";
//    }
    
    Node *node=&list[R-1];
    node->visited=false;
    head=0;
    length=0;
    tail=length-1;
    queue=new Node[N];
    Enqueue(node);
    int current=0;
    while (length>0) {
        node=dequeue();
        while (node->length>0) {
            Node* neighbor=&list[pop(node)];
            if (neighbor->visited) {
                Enqueue(neighbor);
                neighbor->visited=false;
            }
        }
        result->list[current]=node->key;
        current++;
    }
    //print_list(result);
    return result;
}



int main(int argc, const char * argv[]) {
    int T,i;
    cin>>T;
    traversal* result=new traversal[T];
    for (i=0;i<T;i++){
        result[i]=*read_data();
    }
    for (i=0; i<T; i++) {
        print_list(&result[i]);
    }
    return 0;
}
