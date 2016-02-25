//
//  main.cpp
//  Line up
//
//  Created by JU YE on 16/2/24.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    long key;
    struct Node *next;
};

typedef struct Node NODE;


NODE *head=NULL;
NODE *tail=NULL;

void print_list(NODE *head, NODE *tail){
    if (head!=NULL) {
        while (head!=tail) {
            cout<<head->key<<" ";
            head=head->next;
        }
        cout<<head->key;
    }
    cout<<endl;
}

long long read_data(int n){
    long long sum=0;
    NODE *node;
    for (; n>0; n--) {
        int command;
        cin>>command;
        switch (command) {
            case 0://insert操作
                node=new NODE;
                cin>>node->key;//新node赋值
                if (head==NULL) {//如果原LIST为空
                    head=node;//首末项均赋值为node
                    tail=node;
                }else{
                    tail->next=node;//否则将tail的next指向新node
                    tail=node;//将tail指向新node
                }
                break;
            case 1://serve操作
                if (head!=NULL) {//如果HEAD不为空
                    sum+=head->key;
                    node=head;
                    head=head->next;//将HEAD指针指向下一项
                    delete []node;//释放原头节点内存
                    
                }
                break;
            case 2://dismiss操作
                if (head!=NULL) {
                    while (head!=NULL) {
                        node=head;
                        head=head->next;
                        delete []node;
                    }
                }
                break;
            default:
                break;
        }
        print_list(head,tail);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    cout<<read_data(n);
    return 0;
}
