#include <iostream>
#include "string.h"
using namespace std;

void add_array(int a, int *sum){
	*sum+=a;
}

int main(int argc, const char * argv[]) {
	int a;
	int sum=0;
	while(true){
		cin>>a;
		if (a==-1){
			break;
		}else{	
			add_array(a,&sum);
		}
	}
	cout<<sum;
	return 0;
}