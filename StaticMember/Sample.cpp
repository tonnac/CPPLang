#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class A
{
public:
	void ee()
	{
		a = 10;
	}
public:
	static int a;
};

class B : public A
{
public:
	void ww()
	{
		a = 20;
	}
};

int A::a = 5;

int main()
{
	ifstream pe("lll.txt");
	string buffer;

	pe >> buffer;

	if (buffer.empty())
	{
		int d = 5;
	}


	A a;

	a.ee();

	B b;

	b.ww();

	return 0;
}