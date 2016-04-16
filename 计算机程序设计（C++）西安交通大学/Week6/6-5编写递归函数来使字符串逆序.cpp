#include <iostream>
#include "string.h"
using namespace std;

string reverse(string b,int n){
	int length=b.length()-1;
	if (n>length/2)	{
		return b;
	}
	char temp=b[n];
	b[n]=b[length-n];
	b[length-n]=temp;
	return reverse(b,n+1);
}

int main(int argc, const char * argv[]) {
	string b;
	getline(cin,b);
	cout<<reverse(b,0);
	return 0;
}