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


long long* get_child_node(long long* list,int current_postion){
    long long temp=list[current_postion];
    int child_postion;
    int right,left;
    ///明天改
    if (length>2*(current_postion+1)) {//当有两个子节点时
        //left=2*(current_postion+1)-1;
        right=2*(current_postion+1);
        left=right-1;
        if (list[right]<list[left]) {//判断哪个子节点数据比较大，保存大的子节点的位置
            child_postion=left;
        }else{
            child_postion=right;
        }
    }else if (length==2*(current_postion+1)){
        child_postion=length-1;
    }else{
        return  list;
    }
    if (temp< list[child_postion]) {
        list[current_postion]=list[child_postion];
        list[child_postion]=temp;
        list=get_child_node(list, child_postion);
    }
    return list;
}

long long* get_father_node(long long* list,int current_postion){
    long long temp=list[current_postion];
    int father_postion=(current_postion+1)/2-1;
    if (current_postion==0||temp<list[father_postion]) {///顶层或者父节点大于自己
        return list;
    }
    //当前节点与父节点交换位置
    list[current_postion]=list[father_postion];
    list[father_postion]=temp;
    list=get_father_node(list, father_postion);
    return list;
}

long long* pop(long long* list){
    length--;
    //long long* result=new long long[length];
    list[0]=list[length];
//    for (int i=1; i<length; i++) {
//        result[i]=list[i];
//    }
//    
    list=get_child_node(list, 0);
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
    list=get_father_node(list, postion);
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
        //print_list(length, list);
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
