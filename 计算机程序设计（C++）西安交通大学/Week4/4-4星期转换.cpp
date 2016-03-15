#include <iostream>
#include "string.h"
using namespace std;
int main(int argc, const char * argv[]) {
	string list[7]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
	int i;
	cin>>i;
	if (i>7||i<1){
		cout<<"invalid";
	}else{
		cout<<list[i-1];
	}
	return 0;
}