#include "Template.h"

class A
{
	virtual void show() const = 0;
};

class B : public A
{
public:
	B()
	{}
};

template <class L>
void SwapFunc(L& n1, L&n2)
{
	L temp = n1;
	n1 = n2;
	n2 = temp;
}

template <class qwje>
qwje SumArray(qwje arr[], qwje len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

class Point
{
private:
	int xpos;
	int ypos;
	static int Cnt;
public:
	static int getCnt()
	{
		return Cnt;
	}
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << xpos << ", " << ypos << endl;
	}
	int& getXpos(){ return xpos; }
	int& getYpos() { return ypos; }
};

int Point::Cnt = 30;

int main()
{
	/*cout << add(5, 7) << endl;
	cout << add(3.7, 7.5) << endl;
	cout << add<int>(1, 2) << endl;
	cout << add<double>(1.2, 3.2) << endl;
	cout << add<char>(65, 2) << endl;
	cout << add<size_t>(9, 3) << endl;*/

	/*Point ab(3, 5);
	SwapFunc(ab.getXpos(), ab.getYpos());
	ab.ShowPosition();*/

	cout << Point::getCnt() << endl;
	B a;
}