//============================================================================
// Name        : 11-2һ������Person�Ķ��������.cpp
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
		cout << "���� " << Name << endl;
		if (Sex=='m')
		{
			cout << "�Ԅe ��" << endl;
		}else if (Sex=='f')
		{
			cout << "�Ԅe Ů" << endl;
		}
		cout << "���� " << Age << endl;
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
		cout << "������λ " << Dept << endl;
		cout << "��н " << Salary << endl;
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
		cout<<"ѧ�� "<<ID<<endl;
		Person::ShowMe();
		cout<<"�༶ "<<Class<<endl;
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
