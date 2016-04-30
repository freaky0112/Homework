//
//  main.cpp
//  去除字符串首尾多余的空格
//
//  Created by JU YE on 16/4/30.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char* str=new char[100];
    cin.getline(str,100);
    int i=0;
    bool start=true;
    while(str[i]!='#'){
        if (str[i]!=' ')
        {
            start=false;
        }
        if (str[i]==' '&&start)
        {
            str[i]='\0';
        }
        
        i++;
    }
    for (int j = i-1; j >=0; j--)
    {
        //char a=str[j];
        if (str[j]==' ')
        {
            str[j]='\0';
        }else{
            break;
        }
    }
    for (int j = 0; j <= i; ++j)
    {
        if (str[j]!='\0')
        {
            cout<<str[j];
        }
    }
    return 0;
}
