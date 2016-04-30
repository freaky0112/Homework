#include <iostream>
#include "string.h"
using namespace std;

int main(int argc, const char * argv[]) {
	int sum=0;
	int **a;  //指向指针的指针 
    int n,m;//n行 m列 
    int i,j;
    cin>>n>>m; //输入行数和列数
 
    //申请空间
    a= new int * [n];  //n个 int 指针 数组
    for(i=0;i<n;i++)    //n个大小为m的一维数组
    {
        a[i]=new int[m]; //1个大小为m的一维数组，a[i]是int指针
    } 
 
    //输入数据
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //cin>>a[i][j];//输入 
            cin>> *(*(a+i)+j);//同上a相当于行指针 
 			
        }
    }
 
    //输出数据
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //cout<<a[i][j]<<"\t";//输出 
            sum+=*(*(a+i)+j);
 
        }
    }
    cout<<sum;
    //释放申请的空间！！！
    for(i=0;i<n;i++) //释放n个大小为m的一维数组
    {
        delete []a[i]; 
    }
    delete []a;//释放int指针数组
    return 0;
}