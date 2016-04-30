#include <vector>
#include <string>
#include <iostream>
#include <regex>
using namespace std;

vector<string> split(const string &s, const string &seperator){
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;
    
    while(i != s.size()){
        //找到字符串中首个不等于分隔符的字母；
        int flag = 0;
        while(i != s.size() && flag == 0){
            flag = 1;
            for(string_size x = 0; x < seperator.size(); ++x)
                  if(s[i] == seperator[x]){
                      ++i;
                      flag = 0;
                       break;
                      }
        }
        
        //找到又一个分隔符，将两个分隔符之间的字符串取出；
        flag = 0;
        string_size j = i;
        while(j != s.size() && flag == 0){
            for(string_size x = 0; x < seperator.size(); ++x)
                  if(s[j] == seperator[x]){
                      flag = 1;
                       break;
                      }
            if(flag == 0)
                  ++j;
        }
        if(i != j){
            result.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return result;
}

string tentotwo(string ten){
    int number=stoi(ten);
    int n=8;
    char *ip=new char[n];
    for (int i = 0; i < n; ++i)
    {
        ip[i]='0';
    }
    //cout<<ip<<endl;
    while(number!=0){
        number%2?ip[n-1]='1':ip[n-1]='0';
        //ip[n-1]=(int)(number%2);
        number=number/2;
        n--;
    }
    return ip;
}

string transform(string ip){
    vector<string> ips=split(ip,".");
    string result;
    for (int i = 0; i < ips.size(); ++i)
    {
        result+=tentotwo(ips[i]);
    }
    return result;
}

bool isIPAddress(const char *s)
{
    const char *pChar;
    bool rv = true;
    int tmp1, tmp2, tmp3, tmp4, i;

    while( 1 )
    {
        i = sscanf(s, "%d.%d.%d.%d", &tmp1, &tmp2, &tmp3, &tmp4);

        if( i != 4 )
        {
            rv = false;
            break;
        }

        if( (tmp1 > 255) || (tmp2 > 255) || (tmp3 > 255) || (tmp4 > 255) )
        {
            rv = false;
            break;
        }

        for( pChar = s; *pChar != 0; pChar++ )
        {
            if( (*pChar != '.')
                && ((*pChar < '0') || (*pChar > '9')) )
            {
                rv = false;
                break;
            }
        }
        break;
    }

    return rv;
}
int main(int argc, char const *argv[]){
    // string ip;
    // getline(cin,ip);
    char ip[100];
    cin.getline(ip,100);
    if (isIPAddress(ip)){
        cout<<transform(ip);
    }else{
        cout<<"data error";
    }
    return 0;
}