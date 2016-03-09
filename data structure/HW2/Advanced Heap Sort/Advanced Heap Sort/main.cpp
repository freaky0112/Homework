//
//  main.cpp
//  Advanced Heap Sort
//
//  Created by JU YE on 16/2/23.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;
int length=0;
void print_list(int length, int *list){
    
    std::cout<<"\n";
    int n=1;
    for (int i=0; i<length; i++) {
        if (i>pow(2, n)-2) {
            cout<<"\n";
            n++;
        }
        std::cout<<list[i]<<" ";
    }
    std::cout<<"\n";
    
}

//合并数组
int* merge(int* left, int* right, int left_length, int right_length){
    int* list=new int[left_length+right_length];
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

int* merge_sort(int length, int* list){
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

long  top(int* list){
    return list[0];
}


int* pop(int* list){
    length--;
    int postion=0;//POP时初始节点为0节点
    //int* result=new int[length];
    list[postion]=list[length];//将0节点赋值为末位数
    //list=get_child_node(list, 0);
    int number;
    while (true) {
        int child_postion,right,left;
        right=2*postion+2;
        if (length>right) {//当有两个子节点时
            left=right-1;
            if (list[left]>list[right]) {//两个子节点取大值
                child_postion=left;
            }else{
                child_postion=right;
            }
        }else if (length==right){//只有一个子节点时取左边的
            child_postion=right-1;
        }else{//没有子节点时跳出循环
            break;
        }
        number=list[postion];
        if (number>=list[child_postion]) {//当当前节点值大于等于子节点大的一个数的值时，跳出循环
            break;
        }else{//否则交换父节点与子节点的值
            list[postion]=list[child_postion];
            list[child_postion]=number;
            postion=child_postion;
        }
        
    }
    return  list;
}

int* push(int* list,int number){
    int postion=length;
    length++;
    //    int* result=new int[length];
    //    for (int i=0; i<length; i++) {
    //        result[i]=list[i];
    //    }
    list[postion]=number;
    //list=get_father_node(list, postion);
    while (postion>0) {
        int father_postion=(postion+1)/2-1;
        if (number<list[father_postion]) {//与父节点比较
            break;                          //如果比父节点小,则跳出循环
        }else{
            list[postion]=list[father_postion];//否则将父结点与当前结点交换位置
            list[father_postion]=number;
            postion=father_postion;             //当前节点设为原节点父节点
            number=list[postion];               //number为当前节点值
        }
    }
    return list;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,i,j;
    long sum=0;
    cin>>n;
    int *s1=new int[n];
    int *s2=new int[n];
    int *list=new int[n];
    for (i=0; i<n; i++) {
        cin>>s1[i];
    }
    for (i=0; i<n; i++) {
        cin>>s2[i];
    }
    s1=merge_sort(n, s1);
    s2=merge_sort(n, s2);
    for (i=0; i<n; i++) {
        for (j=0; j<n/(i+1); j++) {
            list=push(list, s1[i]+s2[j]);
            if (length>n) {
                list=pop(list);
            }        }
    }
    for (i=0; i<n; i++) {
        sum+=list[i];
    }
    cout<<sum;
    return 0;
}
