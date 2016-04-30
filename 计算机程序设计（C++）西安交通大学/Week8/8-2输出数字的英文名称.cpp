#include <iostream>
#include "string.h"
using namespace std;

int main(int argc, const char * argv[]) {
	string number[12]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve"};
	int i;
	cin>>i;
	cout<<number[i-1];
	return 0;
}