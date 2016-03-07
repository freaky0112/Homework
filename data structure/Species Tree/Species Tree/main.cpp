//
//  main.cpp
//  Species Tree
//
//  Created by JU YE on 16/2/29.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

struct species{
    long key=0;
    struct species* father;
    //struct species* children;
    //int length=0;
};

species* list;
int length=0;

void print_list(){
    cout<<endl;
    for (int i=0; i<length; i++) {
        cout<<list[i].key<<" ";
    }
    cout<<endl;
}

species* looking_for_species(long key){
    species *result;
    for (int i=0; i<length; i++) {
        result=&list[i];
        if (key==result->key) {
            return result;
        }
    }
    result=&list[length];
    return result;
}

long get_result(int Q){
    //print_list();
    long result=0;
    for (; Q>0; Q--) {
        long x;
        cin>>x;
        species* child=looking_for_species(x);
        if (child->father!=NULL&&child->father->father!=NULL) {
            result+=child->father->father->key;
        }
    }
    return result;
}

void read_data(int N){
    list=new species[N+1];
    for (; N>0; N--) {
        long x,y;
        cin>>x>>y;
        species *father,*child;
        father=looking_for_species(x);
        if (father->key==0) {
            father->key=x;
            list[length]=*father;
            length++;
        }
        
        child=looking_for_species(y);

        if (child->key==0) {
            child->key=y;
            list[length]=*child;
            length++;
            //print_list();
        }
        child->father=father;

    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N,Q;
    cin>>N>>Q;
    read_data(N-1);
    cout<<get_result(Q);
    return 0;
}
