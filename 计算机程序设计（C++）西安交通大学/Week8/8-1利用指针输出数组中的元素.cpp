#include <iostream>
#include "string.h"
using namespace std;

void print_list(int* list, int n){
	for (int i = 0; i < n-1; ++i)
	{
		cout<<list[i]<<" ";
	}
	cout<<list[n-1];
}

int main(int argc, const char * argv[]) {
	int n;
	cin>>n;
	int* list=new int[n];
	for (int i = 0; i < n; ++i)
	{
		list[i]=i+1;
	}
	print_list(list,n);
	return 0;
}