#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
	bool judge=true;
	double sum=0;
	int max=-1,min=101;
	for (int i = 0; i < 10; ++i)
	{
		double x;
		cin>>x;
		if (x>100||x<0)
		{
			judge=false;
		}
		if (x>max)
		{
			max=x;
		}
		if (x<min)
		{
			min=x;
		}
		sum+=x;
	}
	if (judge)
	{
		sum=sum-max-min;
		cout<<sum/8;
	}else{
		cout<<"the score is invalid.";
	}
	return 0;
}