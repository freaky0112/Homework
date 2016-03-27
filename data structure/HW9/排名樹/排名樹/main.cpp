//
//  main.cpp
//  排名樹
//
//  Created by JU YE on 16/3/26.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
#include "string.h"
using namespace std;

struct Node{
    int key=-1;
    Node* parent=NULL;
    Node* left=NULL;
    Node* right=NULL;
};

Node* list;

Node* min(Node* node){
    if (node->left==NULL) {
        return node;
    }else{
        return min(node->left);
    }
}

Node* search(Node* root,int key){
    if (root->key==key) {
        return root;
    }else if (root->key>key){
        if (root->left==NULL) {
            return NULL;
        }else{
            return search(root->left,key);
        }
    }else if (root->key<key){
        if (root->right==NULL) {
            return NULL;
        }else{
            return search(root->right,key);
        }
    }
    return NULL;
}

int dfs(Node* node,int count,bool after){
    if (node->left!=NULL) {
        count++;
        count=dfs(node->left,count,true);
    }
    if (node->right!=NULL&&after) {
        count++;
        count=dfs(node->right,count,true);
    }
    return count;
}

int dfs_parent(Node* node,int count,bool after){
    count=dfs(node, count,after);
    if (node->parent==NULL) {
        return count;
    }else if (node->parent->key>node->key){
        return count;
    }else{
        count++;
        return dfs_parent(node->parent,count,false);
    }
    return count;
}

int get_rank(Node* node){
    int count=1;
    //count=dfs(node,count);
    count=dfs_parent(node, count,false);
    return count;
}

bool insert_binary_tree(Node* root,Node* node){
    if (root->key==node->key) {
        return false;
    }else if (root->key>node->key){
        if (root->left==NULL) {
            root->left=node;
            node->parent=root;
            return true;
        }else{
            return insert_binary_tree(root->left,node);
        }
    }else if (root->key<node->key){
        if (root->right==NULL) {
            root->right=node;
            node->parent=root;
            return true;
        }else{
            return insert_binary_tree(root->right,node);
        }
    }
    return false;
}

void read_data(){
    int N,Q;
    cin>>N>>Q;
    int j=0;
    list=new Node[N];
    Node* root = &list[j];
    for (; Q>0; Q--) {
        char command[4];
        cin>>command;
        if (strcmp(command, "add")==0) {
            cin>>list[j].key;
            if (j==0) {
                //root=&list[j];
                j++;
            }else if(insert_binary_tree(root,&list[j])){
                j++;
            }
        }else if (strcmp(command, "rank")==0){
            int key;
            cin>>key;
            Node* node=search(&list[0],key);
            if (node==NULL) {
                cout<<-1<<endl;
            }else{
                cout<<get_rank(node)<<endl;
            }
        }
    
    
    }
    
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for (int i=0; i<T; i++) {
        read_data();
    }
    return 0;
}
