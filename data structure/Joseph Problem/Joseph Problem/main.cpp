//
//  main.cpp
//  Joseph Problem
//
//  Created by JU YE on 16/2/24.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

int* enqueue(int* queue, int number){
    return queue;
}

int* dequeue(int* queue, int number){
    return queue;
}

int joseph(int length, int number){
    int* queue=new int[length];
    for (int i=0; i<length; i++) {
        queue[i]=i+1;
    }
    int head=0;
    int tail=length-1;
    
    
    
    return queue[0];
}

int read_data(int T){
    int sum=0;
    for (; T>0; T--) {
        int length,number;
        cin>>length>>number;
        sum+=joseph(length, number);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    cin>>T;
    cout<<read_data(T);
    return 0;
}
