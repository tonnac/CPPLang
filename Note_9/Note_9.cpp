#include "StringClass.h"
#include <iostream>
using namespace std;

class Base
{
private:
	STRING Name;
public:
	Base()
	{}
	Base(const STRING& src) : Name(src)
	{}
	virtual void ShowState()
	{
		cout << Name;
	}
};

class Simple : public Base
{
private:
	int Age;
public:
	Simple()
	{}
	Simple(const STRING&src, int _Age) : Base(src), Age(_Age)
	{}
	void ShowState()
	{
		Base::ShowState();
		cout << Age << endl;
	}
};

class Third : public Simple
{
public:
	void ShowState()
	{}
	Third()
	{}
};


int main()
{
	Base * bptr = new Base("qqqqq");
	Base * pptr = dynamic_cast<Base*>(bptr);
	Simple * sptr = dynamic_cast<Simple*>(pptr);
	return 0;
}