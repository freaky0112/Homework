#include <iostream>
using namespace std;
inline int length(int a,int b){
	return a+a+b+b;
}

inline int area(int a,int b){
	return a*b;
}

int main(int argc, const char * argv[]) {
	int a,b;
	cin>>a>>b;
	cout<<area(a,b)<<" "<<length(a,b);
	return 0;
}