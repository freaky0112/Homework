#include <iostream>
#include "string.h"
#include "ctype.h"
using namespace std;


void caesar(char s[]) {
	int length = strlen(s);
	for (int i = 0; i < length; i++)
	{
		if (s[i]>='a'&&s[i]<='w')
		{
			s[i] = toupper(s[i]+3);
		}
		else if (s[i]>='x'&&s[i] <= 'z')
		{
			s[i] = toupper(s[i] + 3 - 26);
		}
		else if (s[i]>='A'&&s[i] <= 'W')
		{
			s[i] = tolower(s[i] + 3);
		}
		else if (s[i]>='X'&&s[i] <= 'Z')
		{
			s[i] = tolower(s[i] + 3 - 26);
		}
	}
}
void oddeven(char s[]) {
	int length = strlen(s);
	char* t = new char[length];
	int j = 0;
	for (int i = 0; i < length; i+=2)
	{
		t[j] = s[i];
		j++;
	}
	for (int i = 1; i < length; i+=2)
	{
		t[j] = s[i];
		j++;
	}
	for (int i = 0; i < length; i++)
	{
		s[i] = t[i];
	}
	delete[]t;
}
void cipher(void(*f)(char s[]), char s[]) {
	(*f)(s);
}

int main(int argc, const char * argv[]) {
	char s[100];
	cin.getline(s, 100);
	int n;
	cin >> n;
	switch (n) {
	case 1:
		cipher(caesar, s);
		break;
	case 2:
		cipher(oddeven, s);
		break;
	default:
		break;
	}
	cout << s;
	return 0;
}
