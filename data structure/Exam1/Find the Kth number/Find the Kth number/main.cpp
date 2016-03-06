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

struct function_fx{
    int a,b,k;
};

typedef struct function_fx fx;

int length=0;

int get_value(fx factor){
    return factor.a*factor.k+factor.b;
}

void print_list(int length, fx *list){
    
    std::cout<<"\n";
    int n=1;
    for (int i=0; i<length; i++) {
        if (i>pow(2, n)-2) {
            cout<<"\n";
            n++;
        }
        std::cout<<get_value(list[i])<<" ";
    }
    std::cout<<"\n";
    
}

fx top(fx* list){
    return list[0];
}

void swap(fx* a,fx* b){
    fx temp=*b;
    *b=*a;
    *a=temp;
}


fx* pop(fx* list){
    length--;
    int postion=0;//POP时初始节点为0节点
    int son=postion*2+1;
    //int* result=new int[length];
    list[postion]=list[length];//将0节点赋值为末位数
    while (son<length) {
        if (son+1<length&&get_value(list[son])>get_value(list[son+1])) {//寻找左右子节点较小值
            son++;
        }
        if (get_value(list[postion])<get_value(list[son])) {//如果父节点小于子节点跳出循环
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

fx* push(fx* list,fx number){
    int postion=length;
    length++;
    //    int* result=new int[length];
    //    for (int i=0; i<length; i++) {
    //        result[i]=list[i];
    //    }
    list[postion]=number;
    //cout<<get_value(number)<<endl;
    //list=get_father_node(list, postion);
    while (postion>0) {
        int father_postion=(postion+1)/2-1;
        if (get_value(number)>get_value(list[father_postion])) {//与父节点比较
            break;                          //如果比父节点大,则跳出循环
        }else{
            list[postion]=list[father_postion];//否则将父结点与当前结点交换位置
            list[father_postion]=number;
            postion=father_postion;             //当前节点设为原节点父节点
            number=list[postion];               //number为当前节点值
        }
    }
    return list;
}

int read_data(int N,int M,int K){
    int result;
    fx* list=new fx[N];
    fx* factors=new fx[N];
    int i,mins=1;
    //初始化HEAP
    for (i=0; i<N; i++) {
        fx new_fx;
        new_fx.k=1;
        cin>>new_fx.a>>new_fx.b;
        factors=push(list, new_fx);
    }
    fx min;
    while (mins<K) {
        min=top(list);
        if (min.k+1>M) {//如果k为该列最后一个则直接POP当前数列最小值
            list=pop(list);
            mins++;
        }else{
            min.k++;//否则新的数字的k+1
            list=pop(list);
            list=push(list, min);
            mins++;
        }
        //print_list(length, list);
    }
    //print_list(length, list);
    result=get_value(top(list));
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
