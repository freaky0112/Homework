#include <iostream>
#include "string.h"
using namespace std;

void reset(int *a,int *b){
	*a=(*a+*b+)/2;
	*b=*a;
}

int main(int argc, const char * argv[]) {
	int a,b;
	cin>>a>>b;
	reset(&a,&b);
	cout<<a<<" "<<b;
	return 0;
}