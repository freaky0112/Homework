//============================================================================
// Name        : 11-5从Student类和Teacher类多重派生Graduate类.cpp
// Author      : Freaky
// Version     :
// Copyright   : gun
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
class Person {
protected:
	char Name[10];
	char Sex[10];
	int Age;
public:
	void Register(char *name, int age, char sex) {
		strcpy(Name,name);
		Age = age;
		if(sex=='m'){
			strycpy(Sex,"男");
		}else if(sex=='f'){
			strycpy(Sex,"女");
		}

	}
	void ShowMe() {
	}
};

class Teacher: public Person {
	char Dept[20];
	int Salary;
public:
	Teacher(char *name, int age, char sex, char* dept, int salary) {
		Register(name, age, sex);
		strycpy(Dpet,dept);
		this->Salary = salary;
	}
	void ShowMe() {
		Person::ShowMe();
		cout << "工作单位 " << Dept << endl;
		cout << "月薪 " << Salary << endl;
	}
};

class Student:public Person{
protected:
	char* ID[12];
	char* Class[12];
public:
	Student(char *name,int age,char sex, char *id,char *classid){
		Register(name, age, sex);
		strcpy(ID,id);
		strcpy(Class,classid);
	}
	void ShowMe() {
		cout<<"学号 "<<ID<<endl;
		Person::ShowMe();
		cout<<"班级 "<<Class<<endl;
	}
};

class Graduate:public Teacher,public Student{
public:
	Graduate(char *name,int age,char *sex,char *dept,int salary,char *id,char *classid):
		Teacher(name,age,sex,dept,salary),Student(name,age,sex,id,classid){

	}
	void ShowMe(){

	}
};

int main() {
//	char Name[20];
//	char Sex;
//	int Age;
//	char Dept[10];
//	int Salary;
//	char ID[12];
//	char Class[12];

	return 0;
}
