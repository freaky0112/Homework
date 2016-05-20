#include <iostream>
#include "string.h"
#include <iomanip>
using namespace std;

class Weekday
{
public:
	void SetDay(int num){
		now=num;
	}
	void IncDay(){
		if (now==6){
			now=0;
		}else{
			now++;
		}
	}
	void NowDay(){
		cout<<weekdays[now]<<endl;
	}
private:
	int now;
	string weekdays[7]={"������","����һ","���ڶ�","������","������","������","������"};
};

int main(int argc, const char * argv[]) {
	int now;
	cin>>now;
	Weekday weekday;
	weekday.SetDay(now);
	for (int i = 0; i < 3; ++i)
	{
		weekday.NowDay();
		weekday.IncDay();
	}
	return 0;
}