#include <iostream>
using namespace std;

int isprime(int a){
	if (a==1)
	{
		return 0;
	}
	for (int i = 2; i <= a/2; ++i)
	{
		/* code */
		if (a%i==0)
		{
			/* code */
			return 0;
		}
	}
	return 1;
}

int main(int argc, const char * argv[]) {
	int a,i=0,j;
	int list[100];
	cin>>a;
	while(a!=0){
		if (isprime(a))
		{	
			list[i]=a;
			i++;
		}
		cin>>a;
	}
	for (j = 0; j < i-1; ++j)
	{
		cout<<list[j]<<" ";
	}
	cout<<list[j];
}