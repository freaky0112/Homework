//
//  type2.cpp
//  Line up
//
//  Created by JU YE on 16/2/25.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

long head,tail;
long length=0;
int SIZE=20000;
long long* queue;

/*
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
*/
void print_list(){
    for (int i=0; i<length; i++) {
        int n=(head+i)%SIZE;
        
        cout<<queue[n]<<" ";
    }
    cout<<endl;
}

void enqueue(long number){
    tail=(tail+1)%SIZE;//尾部位置为原位置+1除以总长度求余
    queue[tail]=number;
    length++;
}

long dequeue(){
    long temp=queue[head];
    head++;
    head=head%SIZE;//头部位置为原位置+1除以总长度求余
    length--;
    return temp;
}

long long read_data(int count){
    queue=new long long[SIZE];
    long long sum=0;
    head=0;
    tail=length-1;
    length=0;
    while (count>0) {
        int command;
        cin>>command;
        switch (command) {
            case 0:
                long number;
                cin>>number;
                if (length==0) {
                    head=0;
                    queue[head]=number;
                    tail=0;
                    length++;
                }else{
                    enqueue(number);
                }
                break;
            case 1:
                if (length>0) {
                    sum+=dequeue();
                }
                break;
            case 2:
                length=0;
                head=0;
                break;
            default:
                break;
        }
        print_list();
        count--;
    }
    delete []queue;
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    cout<<read_data(n);
    return 0;
}
