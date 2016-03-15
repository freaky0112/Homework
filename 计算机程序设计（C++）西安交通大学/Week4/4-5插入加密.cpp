#include <iostream>
#include "string.h"
using namespace std;

char* list_low;
char* list_upper;

char Encryption(char a){
	int index;
	int result;
	if (a<='z'&&a>='a')
	{
		index=(a-'a'+3+26)%26;
		result=list_upper[index];
	}
	if (a<='Z'&&a>='A')
	{
		index=(a-'A'+3+26)%26;
		result=list_low[index];
	}
	return result;
}


int main(int argc, const char * argv[]) {
	list_low=new char[26];
	list_upper=new char[26];
	for (int i = 0; i < 26; ++i)
	{
		list_low[i]='a'+i;
		list_upper[i]='A'+i;
	}
	char string[20];
	cin.getline(string, 20);
	char result[strlen(string)];
	for (int i = 0; i < strlen(string); ++i)
	{
		result[i]=Encryption(string[i]);
	}
	cout<<result;
	return 0;
}