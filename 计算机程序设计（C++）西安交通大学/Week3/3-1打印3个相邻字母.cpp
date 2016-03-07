#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
	char a;
	cin>>a;
	if (a=='a'||a=='A')
	{	
		printf("%c", a+25);
	}else{
		printf("%c", a-1);
	}
	printf("%c", a);
	if (a=='z'||a=='Z')
	{
		printf("%c",a-25);
	}else{
		printf("%c",a+1 );
	}
	return 0;
}