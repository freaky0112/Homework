#include <iostream>
using namespace std;

struct song
{
	char name[50];
	char singer[20];
	int clicks;
};
song*  list;

void inversion_sort(){
	for (int i = 0; i < 5; ++i)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (list[j].clicks<list[j+1].clicks)
			{
				song temp=list[j+1];
				list[j+1]=list[j];
				list[j]=temp;
			}
		}
	}
}


int main(int argc, const char * argv[]) {
	list=new song[5];
	for (int i = 0; i < 5; ++i)
	{
		cin>>list[i].name>>list[i].singer>>list[i].clicks;
	}
	inversion_sort();
	for (int i = 0; i < 5; ++i)
	{
		cout<<list[i].name<<" "<<list[i].singer<<" "<<list[i].clicks<<endl;
	}
	return 0;
}