//
//  type2.cpp
//  Line up
//
//  Created by JU YE on 16/2/25.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

int head=0;
int length=0;

long long serve(long long* list){
    head++;
    return list[head-1];
}

long long* insert(long long* list, long long number){
    list[length]=number;
    length++;
    return list;
}

long long read_data(int count){
    long long* list=new long long[20000];
    long long sum=0;
    while (count>0) {
        int command;
        cin>>command;
        switch (command) {
            case 0:
                long number;
                cin>>number;
                list=insert(list, number);
                break;
            case 1:
                if (length>0) {
                    sum+=serve(list);
                }
                break;
            case 2:
                length=0;
                head=0;
                break;
            default:
                break;
        }
        count--;
    }
    return sum;
}

int main2(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    cout<<read_data(n);
    return 0;
}
