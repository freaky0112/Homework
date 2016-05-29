//
//  main.cpp
//  10-3设计带构造函数的Dog类
//
//  Created by JU YE on 16/5/30.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;
class Dog{
    char* name;
    int age;
    char sex;
    double weight;
public:
    Dog(char* n, int a, char s,double w):name(n),age(a),sex(s),weight(w){}
    char* GetName(){
        return name;
    }
    int GetAge(){
        return age;
    }
    char GetSex(){
        return sex;
    }
    double GetWeight(){
        return weight;
    }
    void speak(){
        cout<<"Arf!Arf!"<<endl;
    }
};

int main(int argc, const char * argv[]) {
    char* name;
    int age;
    char sex;
    double weight;
    cin>>name>>age>>sex>>weight;
    Dog* dog=new Dog(name,age, sex,weight);
    cout<<dog->GetName()<<endl;
    cout<<dog->GetAge()<<endl;
    cout<<dog->GetSex()<<endl;
    cout<<dog->GetWeight()<<endl;
    dog->speak();
    delete dog;
    //cout<<name<<endl<<age<<endl<<sex<<endl<<weight<<endl<<"Arf!Arf!"<<endl;
    return 0;
}
