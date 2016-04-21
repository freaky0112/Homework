#include <iostream>
#include "string.h"
using namespace std;

void print(int* list,int length){
	for (int i = 0; i < length-1; ++i)
	{
		cout<<list[i]<<" ";
	}
	cout<<list[length-1];
}

void clear(int n,int* list){
	for (int i = 0; i < n; ++i)
	{
		list[i]=0;
	}
}

int main(int argc, const char * argv[]) {
	int *list=new int[100];
	int i,n;
	for (i = 0; i < 100; ++i)
	{
		int a;
		cin>>a;		
		if (a==-1)
		{
			break;
		}else{
			list[i]=a;
		}
	}
	cin>>n;
	clear(n>i?i:n,list);
	print(list,i);
	return 0;
}