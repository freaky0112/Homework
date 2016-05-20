#include <iostream>
#include "string.h"
#include <iomanip>
using namespace std;

class MyTime
{
public:
	void SetTime(int hh,int mm,int ss){
		hour=hh;
		minute=mm;
		second=ss;
	}
	void print_12(){


		if (hour>=12)
		{
			
			zone[0]='P';
			print(hour-12);
		}else{
			print(hour);
		}
		cout<<":";
		print(minute);
		cout<<":";
		print(second);
		cout<<" "<<zone[0]<<zone[1]<<endl;

	}
	void print_24(){
		print(hour);
		cout<<":";
		print(minute);
		cout<<":";
		print(second);
		cout<<endl;
	}
private:	
	int hour;
	int minute;
	int second;
	char zone[2]={'A','M'};
	void print(int num){
		cout<<setfill('0')<<setw(2)<<num;
	}
};

int main(int argc, const char * argv[]) {
	int hh,mm,ss;
	//cout<<setfill('0')<<setw(2)<<1;
	cin>>hh>>mm>>ss;
	MyTime time;

	time.SetTime(hh,mm,ss);
	time.print_12();
	time.print_24();
	return 0;
}