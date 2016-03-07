#include <iostream>

using namespace std;

void print_result(int men,int women,int children){
	cout<<"men"<<men<<endl;
	cout<<"women"<<women<<endl;
	cout<<"children"<<children<<endl;
}

int main(int argc, const char * argv[]) {
	int max;
	cin>>max;
	int men,women,children;
	bool possible=true;
	for (men=0;men<=max;men++)
	{
		for (women=0;women<=max-men;women++)
		{
			children=max-men-women;
			if (4*men+3*women+children/2==max)
			{
				print_result(men,women,children);
				possible=false;
			}
		}
	}
	if (possible)
	{
		cout<<"no result!";
	}
	return 0;
}