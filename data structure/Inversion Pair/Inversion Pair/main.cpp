//
//  main.cpp
//  Inversion Pair
//
//  Created by JU YE on 16/2/21.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
int count=0;

void print_list(int length, int *list){
    
    std::cout<<"\n";
    for (int i=0; i<length; i++) {
        std::cout<<list[i]<<" ";
    }
    std::cout<<"\n";
    
}

int* delete_first_data(int* list, int length){
    //int length=sizeof(list)/sizeof(int);
    int* new_list=new int[length-1];
    for (int i=0; i<length-1; i++) {
        new_list[i]=list[i+1];
        //std::cout<<new_list[i];
    }
    return new_list;
}
//合并数组
int* merge(int* left, int* right, int left_length, int right_length){
    int* list=new int[left_length+right_length];
    int m=left_length;
    int i=0,K=0,J=0;
    while (left_length>0&&right_length>0) {
        if (left[K]>right[J]) {
            list[i]=right[J];
            //right=delete_first_data(right,right_length);
            right_length--;
            i++;J++;
            count+=m-K;
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

int* read_data(int length){
    int i;
    int *list=new int[length];
    for (i=0; i<length; i++) {
        std::cin>>list[i];
    }
    return list;
}

int main(int argc, const char * argv[]) {
    int length;
    std::cin>>length;
    int *list=read_data(length);
    //int* count=new int{0};
    merge_sort(length,list);
    //print_list(length, merge_sort(length, list));
    std::cout<<count;
    return 0;
}


