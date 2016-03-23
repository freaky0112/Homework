#include <iostream>
#include "string.h"
using namespace std;

int imax(int array[], int count){
	int max=0;
	for (int i = 0; i < count; ++i)
	{
		/* code */
		if (max<array[i])
		{
			max=array[i];
		}
		return max;
	}

}// 求整型数组的最大元素
int imin(int array[], int count){
	int min=100;
	for (int i = 0; i < count; ++i)
	{
		/* code */
		if (min>array[i])
		{
			min=array[i];
		}
		return min;
	}

} // 求整型数组的最小元素


int main(int argc, const char * argv[]) {
	int count;
	cin>>count;
	int a[count];
	for (int i = 0; i < count; ++i)
	{
		cin>>a[i];
	}
	cout<<imax<<endl;
	cout<<imin<<endl;
	return 0;
}