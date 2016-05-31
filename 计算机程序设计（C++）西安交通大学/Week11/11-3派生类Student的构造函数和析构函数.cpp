//============================================================================
// Name        : 11-3派生类Student的构造函数和析构函数.cpp
// Author      : Freaky
// Version     :
// Copyright   : gun
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "iostream"
#include <string.h>
using namespace std;

class Person{
//protected:
	char Name[10]; //姓名
	int Age; //年龄
public:
	Person(char* name,int age){
		strcpy(Name, name);
		Age = age;
		cout<<"constructor of person "<<Name<<endl;
	}
	~Person(){
		cout<<"deconstructor of person "<<Name<<endl;
	}
};

class Student:public Person{
	char ClassName[10]; //班级
	Person Monitor; //班长
public:
	//Student();
	Student(char *name, int age, char *classname, char *name1, int age1):Person(name,age),Monitor(name1,age1){
//		strcpy(Name,name);
//		Age=age;
		strcpy(ClassName,classname);
		//Monitor=new Person(name1,age1);
		cout<<"constructor of Student"<<endl;
	}
	~Student(){
		cout<<"deconstructor of Student"<<endl;
	}

};

int main(int argc, char const *argv[]){
	char Name[10]; //姓名
	int Age; //年龄
	char ClassName[10];
	char Name1[10]; //姓名
	int Age1; //年龄
	cin>>Name>>Age>>ClassName>>Name1>>Age1;
	Student* student=new Student(Name,Age,ClassName,Name1,Age1);
	delete student;
	return 0;
}
