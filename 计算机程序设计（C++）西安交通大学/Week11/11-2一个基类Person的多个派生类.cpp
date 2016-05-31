//============================================================================
// Name        : 11-2一个基类Person的多个派生类.cpp
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
	void Register(char *name, int age, char sex) {
		this->Name = name;
		this->Age = age;
		this->Sex = sex;
	}
	void ShowMe() {
		cout << "姓名 " << Name << endl;
		if (Sex=='m')
		{
			cout << "性別 男" << endl;
		}else if (Sex=='f')
		{
			cout << "性別 女" << endl;
		}
		cout << "年龄 " << Age << endl;
	}
};

class Teacher: public Person {
	char* Dept;
	int Salary;
public:
	Teacher(char *name, int age, char sex, char* dept, int salary) {
		Register(name, age, sex);
		this->Dept = dept;
		this->Salary = salary;
	}
	void ShowMe() {
		Person::ShowMe();
		cout << "工作单位 " << Dept << endl;
		cout << "月薪 " << Salary << endl;
	}
};

class Student:public Person{
	char* ID;
	char* Class;
public:
	Student(char *name,int age,char sex, char *id,char *classid){
		Register(name, age, sex);
		this->ID=id;
		this->Class=classid;
	}
	void ShowMe() {
		cout<<"学号 "<<ID<<endl;
		Person::ShowMe();
		cout<<"班级 "<<Class<<endl;
	}
};

int main() {
	char Name[20];
	char Sex;
	int Age;
	char Dept[10];
	int Salary;
	char Name1[20];
	char Sex1;
	int Age1;
	char ID[12];
	char Class[12];
	cin>>Name>>Age>>Sex>>Dept>>Salary;
	cin>>Name1>>Age1>>Sex1>>ID>>Class;
	Teacher* teacher=new Teacher(Name,Age,Sex,Dept,Salary);
	teacher->ShowMe();
	Student* student=new Student(Name1,Age1,Sex1,ID,Class);
	student->ShowMe();
	return 0;
}
