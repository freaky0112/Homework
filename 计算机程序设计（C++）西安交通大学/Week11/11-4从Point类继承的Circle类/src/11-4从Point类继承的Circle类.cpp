//============================================================================
// Name        : 11-4��Point��̳е�Circle��.cpp
// Author      : Freaky
// Version     :
// Copyright   : gun
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Point {

	int x, y; //���x��y����
public:
	//Point(int = 0, int = 0); // ���캯��
	//void SetPoint(int, int); // ��������
	int GetX() {
		return x;
	} // ȡx����
	int GetY() {
		return y;
	} // ȡy����

	Point(int a = 0, int b = 0) {
		SetPoint(a, b);
//		cout << "Point p ";
//		Print();
	}
	void SetPoint(int a, int b) {
		x = a;
		y = b;
	}
	void Print() {

		cout << "[" << x << "," << y << "]" << endl;
	}
};

class Circle: public Point {
	double radius;
public:
	//Circle(int x = 0, int y = 0 , double r = 0.0):Point(x,y),radius(r);//�����ݳ�Ա��ֵ����ʹ��SetRadius�ͻ����Point
	Circle(int x = 0, int y = 0, double r = 0.0) :
			Point(x, y), radius(r) {
	}
	void SetRadius(double r) {
		radius = r; //���ð뾶
	}
	double GetRadius() {
		return radius; //ȡ�뾶
	}
	double Area() {
		return 3.14 * radius * radius; //�������
	}
	void Print() {
		//���Բ������Ͱ뾶����ʹ�û����Print
		Point::Print();
		cout<<"Radius="<<radius<<endl;
		cout<<"The centre of circle c ";
		Point::Print();
		cout<<"The area of circle c "<<Area()<<endl;
	}
};

int main() {
	int x,y,a,b;
	double r;
	cin>>x>>y>>a>>b>>r;
	Point point(x,y);
	cout<<"Point p ";
	point.Print();
	Circle circle(a,b,r);
	cout<<"Circle c Center=";
	circle.Print();
	return 0;
}
