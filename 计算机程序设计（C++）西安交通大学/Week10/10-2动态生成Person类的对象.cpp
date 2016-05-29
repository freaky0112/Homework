//
//  main.cpp
//  10-1定义一个带重载构造函数的日期类
//
//  Created by JU YE on 16/5/29.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

class Person
{
    char name[20];
    int age;
    char sex;
public:
    Person();
    ~Person(){
        cout<<"Now destroying the instance of Person"；
    }
    void Register(char* name, int age, char sex){
        this->name=name;
        this->age=age;
        this->sex=sex;
    }
    void showme(){
        cout<<name<<" "<<age<<" "<<sex<<endl;
    }
};

Person::Person(){
    name="xxx";
    age=0;
    sex='m';
}

int main(int argc, const char * argv[]) {
    char name[20];
    int age;
    char sex;
    cin>>name>>age>>sex;
    Person* p1=new Person();
    Person* p2=new Person();
    cout<<"person1:";
    p1->showme();
    cout<<"person2:";
    p2->showme();
    p1->Register(name,age,sex);
    p2=p1;
    cout<<"person1:";
    p1->showme();
    cout<<"person2:";
    p2->showme();
    delete[] p1;
    delete[] p2;
    return 0;
}
