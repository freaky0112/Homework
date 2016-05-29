//
//  main.cpp
//  10-2动态生成Person类的对象
//
//  Created by JU YE on 16/5/29.
//  Copyright © 2016年 Freaky. All rights reserved.
//

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
    char* name=new char[20];
    int age;
    char sex;
public:
    Person();
    ~Person(){
        cout<<"Now destroying the instance of Person"<<endl;
    }
    Person(Person* p){
        this->name=p->name;
        this->age=p->age;
        this->sex=p->sex;
    }
    void Register(char* name, int age, char sex){
        this->name=name;
        this->age=age;
        this->sex=sex;
    }
    void showme(){
        cout<<name<<" "<<age<<" "<<sex<<endl;
    };
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
    p2=new Person(p1);
    cout<<"person1:";
    p1->showme();
    cout<<"person2:";
    p2->showme();
    delete p1;
    delete p2;
    return 0;
}
