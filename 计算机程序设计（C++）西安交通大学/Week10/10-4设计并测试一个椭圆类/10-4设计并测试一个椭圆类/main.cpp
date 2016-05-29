//
//  main.cpp
//  10-4设计并测试一个椭圆类
//
//  Created by JU YE on 16/5/30.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;
class Ellipse {
    int x,y,a,b;
    double PI=3.14;
public:
    Ellipse(int,int,double,double);
    double Area(){
        return PI*a*b;
    }
};

Ellipse::Ellipse(int x,int y,double a,double b){
    this->a=a;
    this->b=b;
}

int main(int argc, const char * argv[]) {
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    Ellipse* ellipse=new Ellipse(x,y,a,b);
    cout<<ellipse->Area();
    delete ellipse;
    return 0;
}
