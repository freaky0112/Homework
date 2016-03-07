#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
	int n;
	cin>>n;
	int sum=1;
	for (int i = 1; i < n; ++i)
	{
		sum=(sum+1)*2;
	}
	cout<<sum;
	return 0;
}