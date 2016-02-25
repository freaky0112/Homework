//
//  type2.cpp
//  Line up
//
//  Created by JU YE on 16/2/25.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

long head=0;
long length=0;

void print_list(long long *list){
    for (long i=head; i<head+length; i++) {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

long long serve(long long* list){
    head++;
    length--;
    return list[head-1];
}

long long* insert(long long* list, long long number){
    list[head+length]=number;
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
        print_list(list);
        count--;
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