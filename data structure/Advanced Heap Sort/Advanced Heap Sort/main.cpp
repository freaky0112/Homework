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

long top(long long* list){
    return list[0];
}


long long* get_child_node(long long* list,int current_postion){
    long temp=list[current_postion];
    int child_postion;
    int right,left;
    if (length>2*(current_postion+1)) {
        left=2*(current_postion+1)-1;
        right=2*(current_postion+1);
        if (list[right]>list[left]) {
            child_postion=left;
        }else{
            child_postion=right;
        }
    }else if (length==2*(current_postion+1)){
        child_postion=length-1;
    }else{
        return  list;
    }
    if (temp> list[child_postion]) {
        list[current_postion]=list[child_postion];
        list[child_postion]=temp;
        list=get_child_node(list, child_postion);
    }
    return list;
}

long long* get_father_node(long long* list,int current_postion){
    long temp=list[current_postion];
    int father_postion=(current_postion+1)/2-1;
    if (current_postion==0||temp>list[father_postion]) {///顶层或者父节点小于自己
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

long long* push(long long* list,long number){
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

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,i;
    cin>>n;
    long long *list=new long long[n*n];
    long* s=new long[n];
    for (i=0; i<n; i++) {
        cin>>s[i];
    }
    for (i=0; i<n; i++) {
        int j;
        cin>>j;
        for (int k=0; k<n; k++) {
            list=push(list, j+s[k]);
        }
    }
    long sum;
    for (i=0; i<n; i++) {
        sum+=top(list);
        list=pop(list);
        //print_list(length,list);
    }
    cout<<sum;
    return 0;
}
