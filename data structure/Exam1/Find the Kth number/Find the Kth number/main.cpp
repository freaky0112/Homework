//
//  main.cpp
//  Find the Kth number
//
//  Created by JU YE on 16/3/2.
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

int top(int* list){
    return list[0];
}

void swap(int* a,int* b){
    int temp=*b;
    *b=*a;
    *a=temp;
}


int* pop(int* list){
    length--;
    int postion=0;//POP时初始节点为0节点
    int son=postion*2+1;
    //int* result=new int[length];
    list[postion]=list[length];//将0节点赋值为末位数
    while (son<length-1) {
        if (son+1<length-1&&list[son]<list[son+1]) {
            son++;
        }
        if (list[postion]>list[son]) {
            break;
        }
        else{
            swap(&list[postion], &list[son]);
            postion=son;
            son=postion*2+1;
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

int get_small(int a,int b){
    return a<b?a:b;
}


int read_data(int N,int M,int K){
    int result;
    int* list=new int[K];
    //length=K;
//    for (length=0; length<K; length++) {
//        list[length]=10000*100+100;
//    }
    //print_list(length, list);
    int count=get_small(M, K);
    for (int i=0; i<N; i++) {
        int a,b;
        cin>>a>>b;
        for (int k=1; k<=count; k++) {
            int current=a*k+b;
            if (length<K) {
               list= push(list, current);
            }else{
                if (current>=top(list)) {//如果当前数组最大的数比第k个数大，跳出循环
                    break;
                }else{//否则，删除最大的一个数，将第k个数加入数组
                    list=pop(list);
                    list=push(list, current);
                }
            }
        }
    }
    result=top(list);
    print_list(length, list);
    delete []list;
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N,M,K;
    cin>>N>>M>>K;
    cout<<read_data(N,M,K);
    return 0;
}
