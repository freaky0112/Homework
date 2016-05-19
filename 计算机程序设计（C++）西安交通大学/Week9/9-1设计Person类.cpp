#include <iostream>
#include "string.h"
using namespace std;

class Person{
public:
	//Person();
	//~Person();
	void Register(string a, int b, char c){
		name=a;
		age=b;
		sex=c;
	}
	void ShowMe(){
		cout<<name<<" "<<age<<" "<<sex<<endl;
	}
private:
	string name;
	char sex;
	int age;
};

int main(int argc, const char * argv[]) {
	Person person1;
	Person person2;
	string name;
	int age;
	char sex;
	cin>>name>>age>>sex;
	person1.Register(name,age,sex);
	person2.Register("Zhang3",19, 'm');
	person1.ShowMe();
	person2.ShowMe();
	return 0;
}