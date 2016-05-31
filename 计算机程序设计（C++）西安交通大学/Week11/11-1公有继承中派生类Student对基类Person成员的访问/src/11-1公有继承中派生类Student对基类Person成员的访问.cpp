//============================================================================
// Name        : 11-1公有继承中派生类Student对基类Person成员的访问.cpp
// Author      : Freaky
// Version     :
// Copyright   : gun
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Person {
protected:
	char* Name;
	char Sex;
	int Age;
public:
	void Register(char *name, int age, char sex);
	void
	ShowMe(){
		cout<<Name<<" "<<Age<<" "<<Sex<<endl;
	}
};

class Student:public Person{
	char* classname;
	int number;
public:
	void RegisterStu(char* classname, int number, char *name, int age, char sex){
		this->classname=classname;
		this->number=number;
		this->Name=name;
		this->Sex=sex;
		this->Age=age;
	}
	void ShowStu(){
		cout<<number<<" "<<classname<<" "<<Name<<" "<<Age<<" "<<Sex<<endl;
		//ShowMe();
	}

};

int main() {
	char* classname=new char[10];
	char name[20];
	int number,age;
	char sex;
	cin>>classname>>number>>name>>age>>sex;
	Student* stu=new Student();
	stu->RegisterStu(classname,number,name,age,sex);
	stu->ShowStu();
	stu->ShowMe();
	return 0;
}
