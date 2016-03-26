#include <iostream>
using namespace std;

int imax(int array[], int count){
	int max=0;
	for (int i = 0; i < count; ++i)
	{
		/* code */
		if (max<=array[i])
		{
			max=array[i];
		}
	}
	return max;
}
int imin(int array[], int count){
	int min=101;
	for (int i = 0; i < count; ++i)
	{
		/* code */
		if (min>=array[i])
		{
			min=array[i];
		}
	}
	return min;
}


int main(int argc, const char * argv[]) {
	int count;
	cin>>count;
	int a[count];
	for (int i = 0; i < count; i++)
	{
		cin>>a[i];
	}
	cout<<imax(a,count)<<endl;
	cout<<imin(a,count)<<endl;
	return 0;
}