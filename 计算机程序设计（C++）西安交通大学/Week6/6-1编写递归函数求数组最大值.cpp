#include <iostream>
using namespace std;

int max(int* list,int len){
	if (len==1)
	{
		return list[0];
	}else{
		int a=list[len-1];
		int b=max(list,len-1);
		return a>b?a:b;
	}
}

int main(int argc, const char * argv[]) {
	int n;
	int list[n];
	cin>>n;
	for (int i = 0; i < n; ++i){
		cin>>list[i];
	}
	cout<<max(list,n);
	return 0;
}