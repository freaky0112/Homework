//
//  main.cpp
//  判斷有向圖環的存在
//
//  Created by JU YE on 16/3/18.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int key=-1;
    int* neighbor;
    bool unfinish=true;
    //bool unvisited=true;
    int length=0;
};
bool exist=false;
Node* list;
Node* stack;
int length=0;
void push(Node *node){
    stack[length]=*node;
    length++;
}

Node* pop(){
    length--;
    return &stack[length];
}

bool existed(Node* node){
//    for (int j=0; j<length; j++) {
//        cout<<stack[j].key<<" ";
//    }
    
    for (int i=0; i<length; i++) {
        if (stack[i].key==node->key) {
            exist=true;
            return true;
        }
    }
    return false;
}

bool dfs(Node* node){
    //node->unvisited=false;
    if (existed(node)) {
        return true;
    }
    push(node);
    for (int i=0; i<node->length; i++) {
        Node* neighbor=&list[node->neighbor[i]];
        if (neighbor->unfinish) {
            dfs(neighbor);
        }
    }
    node->unfinish=false;
    pop();
    return false;
}


bool read_data(){
    int N,M;
    cin>>N>>M;
    list=new Node[N];
    stack=new Node[N];
    exist=false;
    for (int i=0; i<M; i++) {
        int ai,bi;
        cin>>ai>>bi;
        if (list[ai-1].key==-1) {
            list[ai-1].key=ai;
            list[ai-1].neighbor=new int[N-1];
        }
        if (list[bi-1].key==-1) {
            list[bi-1].key=bi;
            list[bi-1].neighbor=new int[N-1];
        }
        list[ai-1].neighbor[list[ai-1].length]=bi-1;
        list[ai-1].length++;
    }
    for (int i=0; i<N; i++) {
        if (list[i].unfinish) {
            dfs(&list[i]);
        }
    }
    delete []list;
    delete []stack;
    return false;
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for (int i=0; i<T; i++) {
        read_data();
        exist?cout<<"Yes":cout<<"No";
        cout<<endl;
    }
    return 0;
}
