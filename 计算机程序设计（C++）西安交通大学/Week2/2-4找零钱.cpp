#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
	int sum;
	cin>>sum;
	int fifty=0,twenty=0,ten=0,five=0,one=0;
	while(sum>=50){
		fifty++;
		sum=sum-50;
	}
	while(sum>=20){
		twenty++;
		sum=sum-20;
	}
	while(sum>=10){
		ten++;
		sum=sum-10;
	}
	while(sum>=5){
		five++;
		sum=sum-5;
	}
	one=sum;
	cout<<fifty<<" "<<twenty<<" "<<ten<<" "<<five<<" "<<one;

	return 0;
}