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

bool* list;

void read_data(){
	int N,Q;
    cin>>N>>Q;
    int j=0;
    list=new bool[N];
    for (int i = 0; i < Q; ++i)
    {
    	list[i]=false;
    }
    //Node* root = &list[j];
    for (; Q>0; Q--) {
        char command[4];
        cin>>command;
        int key;
        cin>>key;
        if (strcmp(command, "add")==0) {
            if (!list[key-1]){
            	list[key-1]=true;
            }
        }else if (strcmp(command, "rank")==0){
        	int sum=1;

        	if (list[key-1]){
        		for (int i = 0; i < key-1; ++i){
	            	if (list[i]){
	            		sum++;
	            	}
				} 
            	cout<<sum<<endl;
        	}else{
        		cout<<-1<<endl;
        	}

            
        }
    }
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

