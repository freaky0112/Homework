#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
	char a;
	cin>>a;
	if (a>='a'&&a<='z')
	{
		/* code */
		a=a-32;
	}
	cout<<a;
	return 0;
}