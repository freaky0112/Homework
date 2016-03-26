//
//  main.cpp
//  基本二元搜尋樹
//
//  Created by JU YE on 16/3/26.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* parent;
    Node* left;
    Node* right;
};

Node* list;
int* result;
int length;

void print_list(){
    int i;
    for (i=0; i<length-1; i++) {
        cout<<result[i]<<" ";
    }
    cout<<result[i]<<endl;
}

bool insert_binary_tree(Node* root,Node* node){
    if (root->key==node->key) {
        return false;
    }else if (root->key>node->key){
        if (root->left==NULL) {
            root->left=node;
            return true;
        }else{
            return insert_binary_tree(root->left,node);
        }
    }else if (root->key<node->key){
        if (root->right==NULL) {
            root->right=node;
            return true;
        }else{
            return insert_binary_tree(root->right,node);
        }
    }
    return false;
}

void post_order(Node* node){
    if (node->left!=NULL) {
        post_order(node->left);
    }
    if (node->right!=NULL) {
        post_order(node->right);
    }
    result[length]=node->key;
    length++;
}

void read_data(){
    int count;
    cin>>count;
    length=0;
    list=new Node[count];
    for (int i=0; i<count; i++) {
        cin>>list[i].key;
        insert_binary_tree(&list[0],&list[i]);
    }
    result=new int[count];
    post_order(&list[length]);
    print_list();
    /*
    delete []list;
    delete []result;
    */
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for (int i=0; i<T; i++) {
        read_data();
    }
    return 0;
}
