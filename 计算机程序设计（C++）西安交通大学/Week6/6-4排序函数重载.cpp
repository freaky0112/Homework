#include <iostream>
#include "string.h"
using namespace std;
void sort(int &a,int &b){
	int temp;
	if (a<b){	
		temp=a;
		a=b;
		b=temp;
	}
}

void sort(int &a, int &b,int &c){
  sort(a,b);
  sort(a,c);
  sort(b,c);
}

void sort(int &a, int &b, int &c, int &d){
  sort(a,b,c);
  sort(a,d);
  sort(b,c,d);
}

void sort(int* data, int n){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n-1-i; ++j){
      sort(data[j],data[j+1]);
    }
  }
}

void print(int* data,int n){
  int i;
  for (i = 0; i < n-1; ++i){
    cout<<data[i]<<" ";
  }
  cout<<data[i]<<endl;
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
    case 2:
        cin>>a>>b>>c;
        sort(a,b,c);
        cout<<a<<" "<<b<<" "<<c<<endl;          
        break;      
    case 3:
        cin>>a>>b>>c>>d;
        sort(a,b,c,d);
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        break;  
    case 4:
        cin>>n;
        for(i=0;i<n;i++)
           {
            cin>>data[i];
        } 
        sort(data,n);
        print(data,n);
        break;   
    default:
        break;   
  }
  return 0;
}