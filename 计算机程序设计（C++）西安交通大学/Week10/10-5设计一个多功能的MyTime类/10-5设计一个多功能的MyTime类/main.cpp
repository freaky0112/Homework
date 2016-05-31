//
//  main.cpp
//  10-设计一个多功能的MyTime类
//
//  Created by JU YE on 16/5/30.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
#include "string.h"
#include <iomanip>
using namespace std;

class MyTime
{
public:
    MyTime();
    MyTime(int h, int m,int s):hour(h),minute(m),second(s){}
    
    void SetTime(int hh,int mm,int ss){
        hour=hh;
        minute=mm;
        second=ss;
    }
    void print_12(){
        
        if (hour>=12)
        {
            
            zone[0]='P';
            print(hour-12);
        }else{
            print(hour);
        }
        cout<<":";
        print(minute);
        cout<<":";
        print(second);
        cout<<" "<<zone[0]<<zone[1]<<endl;
        
    }
    void print_24(){
        print(hour);
        cout<<":";
        print(minute);
        cout<<":";
        print(second);
        cout<<endl;
    }
    
    MyTime &operator+(const MyTime &a){
        MyTime time;
        time.hour=a.hour+hour;
        time.minute=a.minute+minute;
        time.second=a.second+second;
        if (time.second>59) {
            time.second-=60;
            time.minute++;
        }
        if (time.minute>59) {
            time.minute-=60;
            time.hour++;
        }
        if (time.hour>23) {
            time.hour-=24;
        }
        return time;
    }
    MyTime &operator-(const MyTime &a){
        MyTime time;
        time.hour=hour-a.hour;
        time.minute=minute-a.minute;
        time.second=second-a.second;
        if (time.second<0) {
            time.second+=60;
            time.minute--;
        }
        if (time.minute<0) {
            time.minute+=60;
            time.hour--;
        }
        if (time.hour<0) {
            time.hour+=24;
        }
        return time;
    }
private:
    int hour;
    int minute;
    int second;
    char zone[2]={'A','M'};
    void print(int num){
        cout<<setfill('0')<<setw(2)<<num;
    }
};

MyTime::MyTime(){
    hour=0;
    minute=0;
    second=0;
}

int main(int argc, const char * argv[]) {
    int hh,mm,ss,h,m,s;
    //cout<<setfill('0')<<setw(2)<<1;
    cin>>hh>>mm>>ss;
    cin>>h>>m>>s;
    MyTime* t1=new MyTime();
    MyTime* t2=new MyTime(8,10,30);
    t1->print_12();
    t1->print_24();
    t2->print_12();
    t2->print_24();
    t1->SetTime(hh,mm,ss);
    MyTime* origin=new MyTime(h,m,s);
    MyTime result=*t1+*origin;
    result.print_12();
    result.print_24();
    result=*t2-*origin;
    result.print_12();
    result.print_24();
    return 0;
}