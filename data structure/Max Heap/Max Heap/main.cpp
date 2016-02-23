//
//  main.cpp
//  Max Heap
//
//  Created by JU YE on 16/2/22.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;
int length=0;
void print_list(int length, long long *list){
    
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

long long top(long long* list){
    return list[0];
}


long long* pop(long long* list){
    length--;
    int postion=0;//POP时初始节点为0节点
    //long long* result=new long long[length];
    list[postion]=list[length];//将0节点赋值为末位数
    //list=get_child_node(list, 0);
    int long long number;
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

long long* push(long long* list,long long number){
    int postion=length;
    length++;
//    long long* result=new long long[length];
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

long long read_data(int count){
    int command;
    long long number;
    long long result;
    long long* list=new long long[20000];
    for (; count>0; count--) {
        cin>>command;
        switch (command) {
            case 0:
                cin>>number;
                list=push(list,number);
                break;
            case 1:
                if (length>0) {
                    list=pop(list);
                }
                break;
            case 2:
                if (length>0) {
                    result+=top(list);
                }
                break;
            default:
                break;
        }
        print_list(length, list);
    }
    delete [] list;
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int count;
    cin>>count;
    long long result=read_data(count);
    cout<<result;
    return 0;
}
