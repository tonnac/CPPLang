#include "Rectangle.h"
#include <iostream>
using namespace std;

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