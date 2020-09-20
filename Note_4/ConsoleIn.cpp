#include <iostream>
#include <conio.h>

class A
{
public:
	A(int e) : a(e)
	{}
	bool	Frame()
	{
		a++;
		return true;
	}
	const int& rea()
	{
		return a;
	}
public:
	int a;
};

class B
{
public:
	B(int e) : d(e)
	{}
private:
	A d;
};

namespace mystd
{
	class istream
	{
	public:
		istream& operator >> (char * str)
		{
			scanf_s("%s", str);
			return *this;
		}
		istream& operator >> (char& str)
		{
			scanf_s("%c", &str);
			return *this;
		}
		istream& operator >> (double& rad)
		{
			scanf_s("%lf", &rad);
			return *this;
		}
		istream& operator >> (int& num)
		{
			scanf_s("%d", &num);
			return *this;
		}
	};

	istream cin;
}

using EINT = int*;

int& wewe(int& b)
{
	return b;
}
const EINT fsdfdsf()
{
	return nullptr;
}
int main()
{
	B d(3);

	using mystd::cin;
	int a;
	cin >> a;
	_getch();
}