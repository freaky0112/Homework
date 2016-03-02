//
//  main.cpp
//  Merge Sort
//
//  Created by JU YE on 16/3/2.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

void print_list(int length, int *list){
    
    std::cout<<"\n";
    for (int i=0; i<length; i++) {
        std::cout<<list[i]<<" ";
    }
    std::cout<<"\n";
    
}


//合并数组
int* merge(int* left, int* right, int left_length, int right_length){
    int* list=new int[left_length+right_length];
    //int m=left_length;
    int i=0,K=0,J=0;
    while (left_length>0&&right_length>0) {
        if (left[K]>right[J]) {
            list[i]=right[J];
            //right=delete_first_data(right,right_length);
            right_length--;
            i++;J++;
        }else{
            list[i]=left[K];
            //left=delete_first_data(left,left_length);
            left_length--;
            i++;K++;
        }
    }
    
    while (left_length>0) {
        list[i]=left[K];
        //left=delete_first_data(left,left_length);
        left_length--;
        i++;K++;
        //count++;
    }
    
    while (right_length>0) {
        list[i]=right[J];
        //right=delete_first_data(right,right_length);
        right_length--;
        i++;J++;
    }
    return list;
}

int* merge_sort(int length, int list[]){
    //int count;
    int right_length=length/2;
    int left_length=length-right_length;
    if (right_length<1) {
        return list;
    }
    
    int* right=new int[right_length];
    int* left=new int[left_length];
    int i=0;
    for (i=0; i<length; i++) {
        if (i<left_length) {
            left[i]=list[i];
        }else{
            right[i-left_length]=list[i];
        }
    }
    
    right=merge_sort(right_length, right);
    left=merge_sort(left_length, left);
    list=merge(left, right, left_length, right_length);
    
    return list;
}

int* read_data(int N){
    int* list=new int[N];
    for (int i=0; i<N; i++) {
        cin>>list[i];
    }
    return merge_sort(N, list);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N,L,R;
    cin>>N;
    int *list=read_data(N);
    cin>>L>>R;
    //print_list(N,list);
    int sum=0;
    for (int i=L; i<=R; i++) {
        sum+=list[i-1];
    }
    cout<<sum;
    return 0;
}
