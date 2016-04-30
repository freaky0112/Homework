#include <iostream>
#include "string.h"
using namespace std;
int *new_array(int n){
	int* list=new int[n];
	return list;
}
void init_array(int *p, int n,int c){
	for (int i = 0; i < n; ++i)
	{
		p[i]=c;
	}
}

void print_list(int* list, int n){
	for (int i = 0; i < n-1; ++i)
	{
		cout<<list[i]<<" ";
	}
	cout<<list[n-1];
}
int main(int argc, const char * argv[]) {
	int n,c;
	cin>>n>>c;
	int* list=new_array(n);
	init_array(list,n,c);
	print_list(list,n);

	return 0;
}