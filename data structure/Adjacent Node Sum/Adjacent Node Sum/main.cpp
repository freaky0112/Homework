//
//  main.cpp
//  Adjacent Node Sum
//
//  Created by JU YE on 16/3/7.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node{
    int key;
    struct Node *neighbor;
    int length=0;
};

Node* list;

int export_result(int Q){
    int sum=0;
    for (; Q>0; Q--) {
        int num;
        cin>>num;
        Node* node=&list[num-1];
        for (int i=0; i<node->length; i++) {
            sum+=node->neighbor[i].key;
        }
    }
    return sum;
}


void read_weight(int M,int N){
    for (int i=0; i<M; i++) {
        int x,y;
        cin>>x>>y;
        Node* node_x=&list[x-1];
        Node* node_y=&list[y-1];
        node_x->key=x;
        node_y->key=y;
        if (node_x->length==0) {
            node_x->neighbor=new Node[N-1];
        }
        node_x->neighbor[node_x->length]=*node_y;
        node_x->length++;
        if (node_y->length==0) {
            node_y->neighbor=new Node[N-1];
        }
        node_y->neighbor[node_y->length]=*node_x;
        node_y->length++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N,M,Q;
    cin>>N>>M>>Q;
    list=new Node[N];
    read_weight(M,N);
    cout<<export_result(Q);
    return 0;
}
