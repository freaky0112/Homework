//
//  main.cpp
//  樹的最長路徑
//
//  Created by JU YE on 16/3/18.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int key=-1;
    int* neighbors;
    int length=0;
    int weight=0;
    bool visted[2]={true,true};
};

Node* list;
Node* current;
int N;//树的节点树
Node* queue;
int head,tail,length=0;

void Enqueue(Node *node){
    tail=(tail+1)%N;
    queue[tail]=*node;
    length++;
}

Node* Dequeue(){
    Node* node=&queue[head];
    head=(head+1)%N;
    length--;
    return node;
}


Node* search(int times,Node* node){
    queue=new Node[N];
    head=0;
    length=0;
    tail=length-1;
    int weight=0;
    node=&list[node->key-1];
    node->weight=0;
    Enqueue(node);
    Node* result = node;
    node->visted[times]=false;
    while (length>0) {
        node=Dequeue();
        for (int i=0; i<node->length; i++) {
            Node* neighbor=&list[node->neighbors[i]];
            if (neighbor->visted[times]) {
                neighbor->visted[times]=false;
                neighbor->weight=node->weight+1;
                Enqueue(neighbor);
            }
        }
        if (weight<node->weight) {
            result=node;
        }
    }
    return result;
}

int read_data(){
    cin>>N;
    list=new Node[N];
    for (int i=0; i<N-1; i++) {
        int number;
        cin>>number;
        if (list[i+1].key==-1) {
            list[i+1].key=i+2;
            list[i+1].neighbors=new int[N];
        }
        list[i+1].neighbors[list[i+1].length]=number-1;
        list[i+1].length++;
        
        if (list[number-1].key==-1) {
            list[number-1].key=number;
            list[number-1].neighbors=new int[N];
        }
        list[number-1].neighbors[list[number-1].length]=i+1;
        list[number-1].length++;
    }
    
    //cout<<list[list[0].neighbors[0]].key<<endl;
    Node* node=&list[0];
    node=search(0,node);
    node=search(1,node);
    return node->weight;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    cin>>T;
    int weight[T];
    for (int i=0; i<T; i++) {
        weight[i]=read_data();
    }
    for (int i=0; i<T; i++) {
        cout<<weight[i]<<endl;
    }
    return 0;
}
