#include "Header.h"


ostream& operator<<(ostream &os, const Point & ref)
{
	os << '[' << ref.m_ix << ", " << ref.m_iy << ']' << endl;
	return os;
}
int operator+(const int & value, const Point &ref)
{
	return value + ref.m_ix + ref.m_iy;
}
Point& operator--(Point &ref)
{
	ref.m_ix--;
	ref.m_iy--;
	return ref;
}
const Point operator--(Point &ref,int)
{
	Point temp = ref;
	ref.m_ix--;
	ref.m_iy--;
	return temp;
}




int main()
{
	Point * p[10];
	for (int i = 0;i < 10;i++)
	{
		p[i] = new Point(rand() % 10, rand() % 10);
		cout << *p[i];
	}
	cout << endl;
	Point p4 = *p[0] + *p[1] + *p[2] + *p[3] + *p[4];
	cout << p4;

	for (int i = 0;i < 10;i++)
	{
		delete p[i];
	}


}