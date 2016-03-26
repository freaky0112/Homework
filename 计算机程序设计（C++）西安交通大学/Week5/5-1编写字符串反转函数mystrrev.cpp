#include <iostream>
#include "string.h"
using namespace std;


int main(int argc, const char * argv[]) {
	char a[100];
	cin.getline(a,100);
	int length=strlen(a);
	for (int i = length-1; i >=0; i--)		
	{
		/* code */
		cout<<a[i];
	}
	return 0;
}