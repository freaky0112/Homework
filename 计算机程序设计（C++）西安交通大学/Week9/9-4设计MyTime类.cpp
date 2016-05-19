#include <iostream>
#include "string.h"
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
			hour=hour-1;
			zone[0]='P';
		}
		cout<<hour<<":"<<minute<<":"<<second<<" "<<zone<<endl;
	}
	void print_24(){
		cout<<hour<<":"<<minute<<":"<<second<<endl;
	}
private:	
	int hour;
	int minute;
	int second;
	char zone[2]={'A','M'};
};

int main(int argc, const char * argv[]) {
	int hh,mm,ss;
	cin>>hh>>mm>>ss;
	MyTime time;
	time.SetTime(hh,mm,ss);
	time.print_12();
	time.print_24();
	return 0;
}