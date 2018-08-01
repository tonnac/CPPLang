#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(const int & x1, const int & y1, const int & x2, const int & y2)
	:upleft(x1, y1), lowright(x2, y2)
{
}


bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
	{
		cout << "�߸��� ��ġ���� ����" << endl;
		return false;
	}
	upleft = ul;
	lowright = lr;
	return true;
}
void Rectangle::ShowRecInfo() const
{
	cout << "�� ���: " << '[' << upleft.GetX() << ", ";
	cout << upleft.GetY() << ']' << endl;
	cout << "�� �ϴ�: " << '[' << lowright.GetX() << ", ";
	cout << lowright.GetY() << ']' << endl;
}