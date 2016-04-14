#include <iostream>
#include "string.h"
using namespace std;
void sort(int a,int b){
	int temp;
	if (a>b){	
		&temp=&a;
		&a=&b;
		&b=&temp;
	}
	delele []temp;
}

int main()
{
int a,b,c,d;
int data[100];
int k,n,i;
  cin>>k;
  switch(k)
  {
    case 1:
        cin>>a>>b;
        sort(a,b);
        cout<<a<<" "<<b<<endl;
        break;
 	defult:
 		break; 
  }
  return 0;
}