#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
	double x,y;
	cin>>x;
	y=sin(x*x)/(1-cos(x));
	cout<<y;
	return 0;
}