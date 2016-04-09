#include <iostream>
#include "string.h"
using namespace std;

int countplus(string origin,int count){
	if (origin.length()>1)
	{
		int a=0,b=0,c=0;
		for (int i = 0; i < origin.length(); ++i)
		{
			if (origin[i]=='.')
			{
				a++;
			}else if (origin[i]==',')
			{
				b++;
			}else if (origin[i]=='?')
			{
				c++;
			}
		}
		if (a+b+c!=origin.length())
		{
			count++;	
		}

	}else if (origin.length()==1)
	{
		/* code */
		if (origin=="."||origin==","||origin=="?")
		{
			/* code */
		}else{
			count++;
		}
	}	
	return count;
}

int get_count(){
	string str;
	getline(cin,str);
	int count=0;
	int start=0;
	string origin;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i]==' ')
		{
			origin=str.substr(start,i-start);
			start=i+1;
			count=countplus(origin,count);
		}
	}
	origin=str.substr(start,str.length()-start);
	count=countplus(origin,count);
	return count;
}

int main(int argc, const char * argv[]) {
	int i=get_count();
	cout<<i;
	return 0;
}