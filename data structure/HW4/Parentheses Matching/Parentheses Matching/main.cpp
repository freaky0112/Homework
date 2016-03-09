//
//  main.cpp
//  Parentheses Matching
//
//  Created by JU YE on 16/2/25.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
#include "string.h"
using namespace std;

bool stack_match(char string[]){
    long count=strlen(string);
    if (count==0) {//如果输入字符串为空字符串，返回true
        return true;
    }else{
        char chars[count];
        int length=0;//初始化字符串长度
        for (int i=0; i<count; i++) {
            char current_char=string[i];
            if (current_char=='{'||current_char=='<'||current_char=='['||current_char=='(') {
                chars[length]=current_char;
                length++;
            }else{
                if (length==0) {//如果字符串长度为0，输入值为右括号则不匹配
                    return false;
                }else{
                    if (current_char=='}') {
                        if (chars[length-1]!='{') {
                            return false;
                        }else{
                            length--;
                        }
                    }else if (current_char==']'){
                        if (chars[length-1]!='[') {
                            return false;
                        }else{
                            length--;
                        }
                    }else if (current_char=='>'){
                        if (chars[length-1]!='<') {
                            return false;
                        }else{
                            length--;
                        }
                    }else if (current_char==')'){
                        if (chars[length-1]!='(') {
                            return false;
                        }else{
                            length--;
                        }
                    }
                }
            }
        }
        if (length==0) {
            return true;
        }else
            return false;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char string[2000];
    int number;
    cin.getline(string, 2000);
    number=atoi(string);
    int sum=0;
    //cin>>string;
    while (number>0) {
        //cin>>string;
        cin.getline(string,2000,'\n');
        //cout<<string;
        stack_match(string)?sum++: sum;
        //cout<<sum<<endl;
        number--;
    }
    cout<<sum;
    return 0;
}
