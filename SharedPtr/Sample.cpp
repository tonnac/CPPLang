#include <iostream>
#include <memory>

using namespace std;

class B
{
public:
	B()
	{
		cout << "B����" << endl;
	}
	~B()
	{
		cout << "B�Ҹ�" << endl;
	}
};

class A
{
public:
	A()
	{
		a = 5;
		cout << "A����" << endl;
	}
	~A()
	{
		cout << "A�Ҹ�" << endl;
	}
	void ep()
	{
		shared_ptr<B> ee(new B);

		return;
	}
	void cd(shared_ptr<A> pa)
	{
		pa->a = 0;
		return;
	}
public:
	int a;
};

int main()
{
	shared_ptr<A> pe(new A);
	shared_ptr<A> pd(new A);
	sizeof(pe);
	pe->cd(pd);
//	shared_ptr<A> e = pe;
//	pe->a = 0;

	int p = 980;

	return 0;
}