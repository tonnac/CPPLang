#include "delegate.cpp"

int QQQ(int d,int b)
{
	std::cout << d << std::endl; return d;
}


int PPP(int e, int a) { std::cout << e+3 << std::endl; return e; }

float SSS(int d) { std::cout << d << std::endl; return 1.1f; }

int main()
{
	MULTICAST_DELEGATE(float, EE, int, ie);

	MULTICAST_DELEGATE(void, QWE);

	EE a;
	a.AddFunc(&SSS);

	Delegate<int, int, int> e;

	e.AddFunc(&QQQ);
	e.AddFunc(&PPP);
	e.AddFunc(&QQQ);

	e.RemoveFunc(&QQQ);

	e.BroadCast(3,4);

	a.BroadCast(34);

	return 0;

}