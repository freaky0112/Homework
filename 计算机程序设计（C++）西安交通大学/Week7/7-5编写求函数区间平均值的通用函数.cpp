#include <iostream>
#include "string.h"
#include "math.h"
using namespace std;
int a, b, c, m;

int  func1(int x) {
	return a*x*x + b*x + c;
}
int  func2(int x) {
	return pow(x, m);
}
int avg(int(*f)(int), int x1, int x2) {
	int sum = 0;
	for (int i = x1; i <= x2; ++i)
	{
		sum += f(i);
	}
	return sum / (x2 - x1+1);
}

int main(int argc, const char * argv[]) {
	cin>>a>>b>>c>>m;
	int x1,x2;
	cin>>x1>>x2;
	cout << avg(func1, x1, x2)<<endl;
	cout << avg(func2, x1, x2)<<endl;
	return 0;
}