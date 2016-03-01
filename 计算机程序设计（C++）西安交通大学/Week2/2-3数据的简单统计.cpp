#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
	long a,b,c;
	cin>>a>>b>>c;
	long sum,avg;
	double avg_d;
	sum=a+b+c;
	avg_d=(double)sum/3;
	avg=int(avg_d+0.5);
	cout<<sum<<endl;
	cout<<avg_d<<endl;
	cout<<avg<<endl;
	return 0;
}