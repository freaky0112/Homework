#include <iostream>
#include "string.h"
using namespace std;
class Point
{
public:
	int X(){return x;}
	int Y(){return y;}
private:
	int x;
	int y;
};

class Trapezium
{
public:
	void initial(int a,int b,int c,int d,int e,int f,int g,int h){
		x1=0;x2=0;x3=0;x4=0;y1=0;y2=0;y3=0;y4=0;
	}
	void GetPosition(int& a,int& b,int& c,int& d, int& e,int& f,int& g,int& h){
		x1=a;y1=b;x2=c;y2=d;x3=e;y3=f;x4=g;y4=h;
	}
	int Area(){
		int area;
		area=((x2-x1)+(x4-x3))*(y2-y4)/2;
		return area;
	}
private:
	int x1,x2,x3,x4,y1,y2,y3,y4;
};

int main(int argc, const char * argv[]) {
	Trapezium trapezium;
	int a,b,c,d,e,f,g,h;
	cin>>a>>b>>c>>d>>e>>f>>g>>h;
	trapezium.GetPosition(a,b,c,d,e,f,g,h);
	cout<<trapezium.Area();
	return 0;
}