//
//  main.cpp
//  二元搜尋樹recovery
//
//  Created by JU YE on 16/4/7.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int key=-1;
    Node* left=NULL;
    Node* right=NULL;
};

Node* list;
int length;

bool binary_tree_insert(Node* root,Node* node){
    if (root->key==node->key) {
        return false;
    }else if (root->key>node->key){
        if (root->left==NULL) {
            root->left=node;
            return true;
        }else{
            binary_tree_insert(root->left, node);
        }
    }else{
        if (root->right==NULL) {
            root->right=node;
            return true;
        }else{
            binary_tree_insert(root->right, node);
        }
    }
    return false;
}

void post_order(Node* node, int root){
    if (node->left!=NULL) {
        post_order(node->left,root);
    }
    if (node->right!=NULL) {
        post_order(node->right,root);
    }
    cout<<node->key;
    node->key!=root?cout<<" ":cout<<endl;
}

void read_data(){
    cin>>length;
    list=new Node[length];
    Node* root=&list[0];
    for (int i=0; i<length; i++) {
        cin>>list[i].key;
        binary_tree_insert(root,&list[i]);
    }
    post_order(root, root->key);
    delete []list;
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for (int i=0; i<T; i++) {
        read_data();
    }
    return 0;
}
