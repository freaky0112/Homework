//
//  main.cpp
//  Insertion Sort
//
//  Created by JU YE on 16/2/21.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>


void print_list(int length, int list[]){
    for (int i=0; i<length; i++) {
        std::cout<<list[i]<<" ";
    }
    std::cout<<"\n";

}

int insertion_sort(int length,int list[]){
    int count=0;
    int i,x,j;
    for (i=1; i<length; i++) {//从第i个数开始检查，一直到最后一个，i初始值为数列第二个数
        x=list[i];
        for (j=i-1; j>=0; j--) {//从第i个数的前一个数开始比对，直到第一个数
            if (list[j]>x) {//如果前一个数比当前值大
                list[j+1]=list[j];//则当前值设为前一个数的值
                count++;//每交换一次计数加1
            }else{
                list[j+1]=x;//否则，当前值设为原第i个数值
                break;//跳出循环
            }
        }
        if (list[0]>x) {//当前面所有数遍历完都比X值大时，将第一个数赋值为X
            list[0]=x;
        }
        
    }
    //print_list(length, list);
    //std::cout<<count;
    return count;
}


int read_data(){
    int length;
    int i;
    std::cin>>length;
    int list[length];
    for (i=0; i<length; i++) {
        std::cin>>list[i];
    }
    int count=insertion_sort(length,list);
    return count;
    //return list;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int count;
    int result=0;
    std::cin>>count;
    while (count>0) {
        result+= read_data();
        count--;
    }
    std::cout<<result;
    //std::cout << "Hello, World!\n";
    return 0;
}




