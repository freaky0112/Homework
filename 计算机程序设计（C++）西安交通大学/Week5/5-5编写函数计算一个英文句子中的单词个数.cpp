#include <iostream>
using namespace std;

int get_count(){
	char a[100];
	int i=0;
	bool judge=true;
	while(cin.get()!='\n'){
		if (a[0]!='.'||a[0]!=','||a[0]!='?')
		{
			i++;
		}
		cin>>a;

	}
	return i;
}

int main(int argc, const char * argv[]) {
	int i=get_count();
	cout<<i;
	return 0;
}