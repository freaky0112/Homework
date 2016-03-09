//
//  main.cpp
//  Joseph Problem
//
//  Created by JU YE on 16/2/24.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

int head,length,tail;//head和tail从0开始
int counts;
int* queue;

void print_list(){
    for (int i=0; i<length; i++) {
        int n=(head+i)%counts;
        
        cout<<queue[n]<<" ";
    }
    cout<<endl;
}

void enqueue(int number){
    tail=(tail+1)%counts;//尾部位置为原位置+1除以总长度求余
    queue[tail]=number;
    length++;
}

int dequeue(){
    int temp=queue[head];
    head++;
    head=head%counts;//头部位置为原位置+1除以总长度求余
    length--;
    return temp;
}

int joseph(int m){
    int i;
    int temp;
    queue=new int[length];
    for (i=0; i<length; i++) {
        queue[i]=i+1;
    }
    head=0;
    tail=length-1;
    while (length>1) {
        for (i=0; i<m%length; i++) {//向后移动m个人，当队伍长度小于m时，移动m%length个人
            temp=dequeue();
            enqueue(temp);
        }
        temp=dequeue();//向后移一个人
        enqueue(temp);
        temp=dequeue();//砍了
        //print_list();
    }
    
    
    return queue[head];
}

int read_data(int T){
    int sum=0;
    for (; T>0; T--) {
        int number;
        cin>>length>>number;
        counts=length;
        sum+=joseph(number);
        delete [] queue;
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
