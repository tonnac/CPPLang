#include <iostream>

using namespace std;

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	Base() : num1(1), num2(2), num3(3)
	{}
};

class Derived : public Base 
{
public:
	void Show();
};

void Derived::Show()
{
	cout << num2 << endl;
}
int main()
{
	Derived drv;
	drv.Show();
}