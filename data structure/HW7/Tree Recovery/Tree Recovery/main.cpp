//
//  main.cpp
//  Tree Recovery
//
//  Created by JU YE on 16/3/15.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
#include "string.h"
using namespace std;
struct Node{
    char key;
    Node *left;
    Node *right;
};

//string str;
long find_index(char key, char* strings,long length){
    long i;
    for (i=0; i<length;i++) {
        if (strings[i]==key) {
            return i;
        }
    }
    return -1;
}

char* sub_string(char* string,long index, long length){
    char* result=new char[length];
    for (int i=0; i<length; i++) {
        result[i]=string[i+index];
    }
    return result;
}

void recovery(char* in,char* pre,Node* node,long length){
    long index=find_index(node->key,in, length);
    if (length>0) {
        if (index==0) {
            node->left=NULL;
        }else{
            node->left=new Node;
            node->left->key=pre[1];
            recovery(sub_string(in,0, index), sub_string(pre, 1, index), node->left,index);
            //recovery(in.substr(0,index), pre.substr(1,index), node->left);
        }
        if (index==length-1) {
            node->right=NULL;
        }else{
            //index++;
            node->right=new Node;
            node->right->key=pre[index+1];
//            recovery(in.substr(index+1,in.length()-index), pre.substr(index+1,pre.length()-index), node->right);
            recovery(sub_string(in, index+1, length-index-1), sub_string(pre, index+1, length-index-1), node->right,length-index-1);
        }
    }
}

void post_order_traversal(Node* node){
    if (node->left!=NULL) {
        post_order_traversal(node->left);
    }
    if (node->right!=NULL) {
        post_order_traversal(node->right);
    }

    cout<<node->key;
    delete []node;
    
}

void read_data(){
    char in[26],pre[26];
    cin>>pre>>in;
    long length=strlen(pre);
    Node* root=new Node;
    root->key=pre[0];
    recovery(in, pre, root,length);
    post_order_traversal(root);
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for (int i=0; i<T; i++) {
        read_data();
        cout<<endl;
    }
    return 0;
}
