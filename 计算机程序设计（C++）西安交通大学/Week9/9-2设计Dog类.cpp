#include <iostream>
#include "string.h"
using namespace std;

class Dog
{
public:
	void setdata(string a,int b,char c,double d){
		name=a;
		age=b;
		sex=c;
		weight=d;
		cout<<"It is my dog."<<endl;
		GetName();
		GetAge();
		Getsex();
		GetWeight();
	}
	void GetName(){
		cout<<"Its name is "<<name<<".\n";
	}
	void GetAge(){
		cout<<"It is "<<age<<" years old.\n";
	}
	void Getsex(){
		if (sex=='m'){
			cout<<"It is male."<<endl;
		}else if (sex=='f'){
			cout<<"It is female."<<endl;
		}
	}
	void GetWeight(){
		cout<<"It is "<<weight<<" kg."<<endl;
	}
private:
	string name;
	int age;
	char sex;
	double weight;
};

int main(int argc, const char * argv[]) {
	Dog dog;
	string name;
	int age;
	char sex;
	double weight;
	cin>>name>>age>>sex>>weight;
	dog.setdata(name,age,sex,weight);
	return 0;
}