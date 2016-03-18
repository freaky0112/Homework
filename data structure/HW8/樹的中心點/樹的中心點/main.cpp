//
//  main.cpp
//  樹的中心點
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
    int eccentricity=0;
    bool* visted;
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


//合并数组
Node* merge(Node* left, Node* right, int left_length, int right_length){
    Node* list=new Node[left_length+right_length];
    int i=0,K=0,J=0;
    while (left_length>0&&right_length>0) {
        if (left[K].eccentricity>right[J].eccentricity) {
            list[i]=right[J];
            //right=delete_first_data(right,right_length);
            right_length--;
            i++;J++;
        }else{
            list[i]=left[K];
            //left=delete_first_data(left,left_length);
            left_length--;
            i++;K++;
        }
    }
    
    while (left_length>0) {
        list[i]=left[K];
        //left=delete_first_data(left,left_length);
        left_length--;
        i++;K++;
        //count++;
    }
    
    while (right_length>0) {
        list[i]=right[J];
        //right=delete_first_data(right,right_length);
        right_length--;
        i++;J++;
    }
    return list;
}

Node* merge_sort(int length, Node list[]){
    //int count;
    int right_length=length/2;
    int left_length=length-right_length;
    if (right_length<1) {
        return list;
    }
    
    Node* right=new Node[right_length];
    Node* left=new Node[left_length];
    int i=0;
    for (i=0; i<length; i++) {
        if (i<left_length) {
            left[i]=list[i];
        }else{
            right[i-left_length]=list[i];
        }
    }
    
    right=merge_sort(right_length, right);
    left=merge_sort(left_length, left);
    list=merge(left, right, left_length, right_length);
    
    return list;
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
    delete []queue;
    return result;
}

void read_data(){
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
    //cout<<"result:"<<endl;
    for (int i=0; i<N; i++) {
        list[i].visted=new bool[N];
        for (int j=0; j<N; j++) {
            list[i].visted[j]=true;
        }
    }
    for (int i=0; i<N; i++) {
        Node* node=&list[i];
        if (node->eccentricity==0) {
            Node *farest=search(i,node);
            node->eccentricity=farest->weight;
            if (farest->eccentricity==0) {
                farest->eccentricity=farest->weight;
            }
        }
    //cout<<node->eccentricity<<endl;
    }
    
    list=merge_sort(N,list);
    int eccentricity=list[0].eccentricity;
    int count=0;
    int* result=new int[N];
    for (int i=0; i<N; i++) {
        if (list[i].eccentricity==eccentricity) {
            result[count]=list[i].key;
            count++;
        }
    }
    delete []list;
    cout<<count<<endl;
    int k;
    for (k=0; k<count-1; k++) {
        cout<<result[k]<<" ";
    }
    cout<<result[k]<<endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    cin>>T;
//    int weight[T];
    for (int i=0; i<T; i++) {
        read_data();
    }
//    for (int i=0; i<T; i++) {
//        cout<<weight[i]<<endl;
//    }
    return 0;
}
