//
//  main.cpp
//  走下去
//
//  Created by JU YE on 16/4/7.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int key=-1;
    int* neighbors;
    int length=0;
    bool visited=false;
    bool circled=false;
};

struct Result{
    int count=0;
    int* list;
};

Node* list;

void print_result(Result result){
    cout<<result.count<<endl;
    int i;
    for (i=0; i<result.count; i++) {
        cout<<result.list[i];
        if (i!=result.count-1) {
            cout<<" ";
        }
    }
    cout<<endl;
}

bool dfs(Node* node){
    if (node->visited) {
        node->circled=true;
        return true;
    }else{
        node->visited=true;
    }
    for (int i=0; i<node->length; i++) {
        Node* neighbor=&list[node->neighbors[i]];
        dfs(neighbor);
        if (neighbor->circled) {
            node->circled=true;
            return true;
        }
    }
    node->visited=false;
    return false;
}

Result find_circle(Result result,int N){
    for (int j=0; j<N; j++) {
//        for (int i=0; i<N; i++) {
//            list[i].visited=false;
//        }
        Node* node=&list[j];
        if (!node->circled) {
            dfs(node);
        }
    }
    for (int i=0; i<N; i++) {
        if (list[i].circled) {
            result.list[result.count]=list[i].key;
            result.count++;
        }
    }
    delete []list;
    return result;
}

Result read_data(){
    Result result;
    int N,M;
    cin>>N>>M;
    list=new Node[N];
    result.list=new int[N];
    for (int i=0; i<N; i++) {
        list[i].key=i+1;
        list[i].neighbors=new int[N];
    }
    
    
    for (int i=0; i<M; i++) {
        int a,b;
        cin>>a>>b;
//        if (list[a-1].key==-1) {
//            list[a-1].key=a;
//            list[a-1].neighbors=new int[N-1];
//        }
//        if (list[b-1].key==-1) {
//            list[b-1].key=b;
//            list[b-1].neighbors=new int[N-1];
//        }

        list[a-1].neighbors[list[a-1].length]=b-1;
        list[a-1].length++;
    }
    result=find_circle(result,N);
    return result;
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    Result* results=new Result[T];
    for (int i=0; i<T; i++) {
        results[i]=read_data();
    }
    for (int i=0; i<T; i++) {
        print_result(results[i]);
    }
    return 0;
}
