//
//  main.cpp
//  Species Tree
//
//  Created by JU YE on 16/2/29.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;


int* list=new int[1000000];

int get_result(int Q){
    int sum=0;
    for (int i=0; i<Q; i++) {
        int x;
        cin>>x;
        x=list[x-1];
        if (x!=0) {
            x=list[x];
        }
        if (x!=0) {
            sum+=x+1;
        }
    }
    return sum;
}

void read_data(int N){
    //list=new species[N+1];
    //list=new species[1000000];
    for (; N>0; N--) {
        int x,y;
        cin>>x>>y;
        list[y-1]=x-1;

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
