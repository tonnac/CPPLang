#include <iostream>
using namespace std;

class Number
{
private:
	int b;
	int num;
	int a;
public:
	Number(int _a = 0) : a(_a), b(30) {}
	void ShowData() { cout << b << " " << num << " " << a << endl; }

	Number& operator*()
	{
		return *this;
	}
	Number* operator->()
	{
		return this;
	}
};

int main(void)
{
	Number dd;
	dd.ShowData();

	(*dd) = 50;
	dd.operator->()->ShowData();
	(dd.operator*()).ShowData();

	return 0;
}