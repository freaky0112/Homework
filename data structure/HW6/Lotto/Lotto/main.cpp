//
//  main.cpp
//  Lotto
//
//  Created by JU YE on 16/3/9.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace::std;



int combination(int N,int M){
    int result=0;
    int a=1,b=1;
    for (int i=1; i<=M; i++) {
        a*=N;
        N--;
        b*=i;
    }
    result=a/b;
    return result;
}

int* row_plus(int* row,int N,int M){
    int current;
    for (int i=M-1; i>=0; i--) {
        current=row[i]+1;
        if (current<=N-(M-i)+1) {
            row[i]=current;
            for (int j=1; j<M-i; j++) {
                row[i+j]=current+j;
            }
            return row;
        }
    }
    return row;
}

int read_data(){
    int N,M,X,Y;
    cin>>N>>M>>X>>Y;
    int length=combination(N, M);
    int lotto[length][M];
    for (int i=0; i<M; i++) {
        lotto[0][i]=i+1;
    }
    for (int i=1; i<length; i++) {
        int* row=new int[M];
        for (int j=0; j<M; j++) {
            row[j]=lotto[i-1][j];
        }
        row=row_plus(row,N,M);
        for (int j=0; j<M; j++) {
            lotto[i][j]=row[j];
        }
    }
    
//    for (int i=0; i<length; i++) {
//        for (int j=0; j<M; j++) {
//            cout<<lotto[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    
    return lotto[X-1][Y-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    int sum=0;
    cin>>T;
    for (; T>0; T--) {
        sum+=read_data();
    }
    cout<<sum;
    return 0;
}
