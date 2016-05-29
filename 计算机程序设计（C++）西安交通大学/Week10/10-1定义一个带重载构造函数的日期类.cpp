//
//  main.cpp
//  10-1定义一个带重载构造函数的日期类
//
//  Created by JU YE on 16/5/29.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;
class Date{
public:Date();
    Date(int y, int m, int d):year(y),mouth(m),day(d){};
    void init(int year,int mouth,int day){
        this->year=year;
        this->mouth=mouth;
        this->day=day;
    }
    void print(){
        cout<<year<<"-"<<mouth<<"-"<<day<<endl;
    }
private:
    int year;
    int mouth;
    int day;
};

Date::Date(){
    year=1900;
    mouth=1;
    day=1;
}

int main(int argc, const char * argv[]) {
    int year,mouth,day;
    cin>>year>>mouth>>day;
    
    Date d1;
    d1.init(1900,1,1);
    d1.print();
    Date* d2=new Date(2100,12,12);
    d2->print();
    d1.init(year,mouth,day);
    d1.print();
    return 0;
}
