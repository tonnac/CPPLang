#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "StringClass.h"

//namespace std
//{
//	class ostream
//	{
//	public:
//		ostream& operator << (char *str)
//		{
//			printf("%s", str);
//			return *this;
//		}
//		ostream& operator << (int num)
//		{
//			printf("%d", num);
//			return *this;
//		}
//		ostream& operator << (double f)
//		{
//			printf("%g", f);
//			return *this;
//		}
//		ostream& operator << (char ch)
//		{
//			printf("%c", ch);
//			return *this;
//		}
//
//		ostream& operator<< (ostream& (*fp)(ostream& os))
//		{
//			return fp(*this);
//		}
//	};
//	class istream
//	{
//	public:
//		istream& operator >> (char * str)
//		{
//			scanf("%s", str);
//			return *this;
//		}
//		istream& operator >> (int& num)
//		{
//			scanf("%d", &num);
//			return *this;
//		}
//		istream& operator >> (double& f)
//		{
//			scanf("%lf", &f);
//			return *this;
//		}
//		istream& operator >> (char& ch)
//		{
//			scanf("%c", &ch);
//			return *this;
//		}
//	};
//	ostream& endl(ostream& ostm)
//	{
//		ostm << '\n';
//		fflush(stdout);
//		return ostm;
//	}
//	istream cin;
//	ostream cout;
//}

class A
{
private :
	STRING Name;
public:
	A(const char*_name) : Name(_name)
	{}
};

int main()
{
	A d("qweqwe");
	d("qweqwsd");
	return 0;
}