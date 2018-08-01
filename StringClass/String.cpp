#include "StringClass.h"

int main()
{
	STRING str1("qwe");
	STRING str2("zzz");
	STRING str3 = "eee";
	STRING str4 = "aaa";
	str4 += str3;
	STRING str5 = str1 + str2;
	STRING str6;
	cin >> str6;
	cout << str6;
	return 0;
}