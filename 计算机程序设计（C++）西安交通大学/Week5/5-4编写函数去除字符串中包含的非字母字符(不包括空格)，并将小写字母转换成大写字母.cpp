#include <iostream>
#include "string.h"
using namespace std;

char upper(char chr){
	if (chr>='a'&&chr<='z')
	{
		chr=chr+'A'-'a';
	}else if ((chr>='A'&&chr<='Z')||chr==' ')
	{
		chr=chr;
	}else{
		chr=0;
	}
	return chr;
}

char* getResult(char list[]){
	int length=strlen(list);
	int j=0;
	char* result=new char[length];
	for (int i = 0; i < length; ++i)
	{
		char a=upper(list[i]);
		if (a!=0)
		{
			result[j]=a;
			j++;
		}
	}
	return result;
}

int main(int argc, const char * argv[]) {
	char list[500];
	cin.getline(list,500);
	cout<<getResult(list);
}