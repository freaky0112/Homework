#include <iostream>
#include "string.h"
using namespace std;

int main(int argc, const char * argv[]) {
	int n;
	cin>>n;
	int sum=0;
	int arr[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>arr[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		sum+=arr[i][i];
	}
	cout<<sum;
	//delete []arr;
	return 0;
}