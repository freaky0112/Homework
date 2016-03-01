#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
	int sum;
	cin>>sum;
	cout<<sum/50<<" ";
	sum=sum%50;
	cout<<sum/20<<" ";
	sum=sum%20;
	cout<<sum/10<<" ";
	sum=sum%10;
	cout<<sum/5<<" "<<sum%5;
	return 0;
}