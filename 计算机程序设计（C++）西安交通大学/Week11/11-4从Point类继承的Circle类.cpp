//============================================================================
// Name        : 11-4从Point类继承的Circle类.cpp
// Author      : Freaky
// Version     :
// Copyright   : gun
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Point {
protected:
	int x, y; //点的x和y坐标
public:
	//Point(int = 0, int = 0); // 构造函数
//	void SetPoint(int, int); // 设置坐标
	int GetX() {
		return x;
	} // 取x坐标
	int GetY() {
		return y;
	} // 取y坐标

	Point(int a = 0, int b = 0) {
		SetPoint(a, b);
		cout<<"Point p ";
		Print();
	}
	void SetPoint(int a, int b) {
		x = a;
		y = b;
	}
	void Print() {

		cout << "[" << x << "," << y << "]"<<endl;
	}
};

class Circle: public Point {
	double radius;
	double PI=3.14;
public:
	Circle(int x = 0, int y = 0 , double r = 0.0):Point(x,y),radius(r);//对数据成员赋值，并使用SetRadius和基类的Point
	void SetRadius(double r) {
		radius = r; //设置半径
	}
	double GetRadius() {
		return radius; //取半径
	}
	double Area(){
		return PI*radius*radius;//计算面积
	}
	void Print(){
		//输出圆心坐标和半径，并使用基类的Print
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
