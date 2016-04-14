#include <iostream>
#include "string.h"
using namespace std;
void print_spaced(char* str){
	int length=strlen(str);
	int i=0;
	for (i = 0; i < length-1; ++i)
	{
		cout<<str[i]<<" ";
	}
	cout<<str[i]<<endl;
}

void print_spaced(string str){
	int length=str.length();
	int i=0;
	for (i = 0; i < length-1; ++i)
	{
		cout<<str[i]<<" ";
	}
	cout<<str[i]<<endl;
}

int main(int argc, const char * argv[]) {
	char* a=new char[100];
	string b;
	cin.getline(a,100);
	getline(cin,b);
	print_spaced(a);
	print_spaced(b);
	return 0;
}