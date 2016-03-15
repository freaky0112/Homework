#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
	int n;
	cin>>n;
	if (n<1||n>5){
		cout<<"matrix order error";
	}else{
		int matrix[n][n];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>matrix[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<matrix[j][i];
				if (j<n-1)
				{
					cout<<" ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}