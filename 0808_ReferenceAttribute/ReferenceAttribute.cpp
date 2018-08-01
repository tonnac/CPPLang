#include <iostream>

using namespace std;

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};
class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};
class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

class Hone
{
public:
	Hone(First & a, First & b, First & c)
	{
		e[0] = &a;
		e[1] = &b;
		e[2] = &c;
	}
	void Func(First & a)
	{
		a.SimpleFunc();
	}
	First * e[3];
};

int main()
{
	Third obj;
	/*obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();*/

	Second & sref = obj;
	/*sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();*/

	First & fref = obj;
	//fref.FirstFunc();
	//fref.SimpleFunc();
	Hone D(obj, sref, fref);
	D.Func(*(D.e[0]));
	D.Func(*(D.e[1]));
	D.Func(*(D.e[2]));

}