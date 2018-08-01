#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	int m_ix;
	int m_iy;
public:
	Point(int x = 0, int y = 0) : m_ix(x), m_iy(y)
	{}
	Point(const Point& cpy);
	Point operator + (const Point& cpy);
	Point operator - (const Point& cpy);
	Point& operator = (const Point& cpy);
	Point& operator += (const Point& cpy);
	Point& operator ++();
	Point& operator ++(int);
	int operator [](const int& index) const;
	bool operator ==(const Point& cpy) const;
	int operator+(const int & value);
	void* operator new(size_t size)
	{
		cout << "Operator new()" << endl;
		void* adr = new char[size];
		return adr;
	}
	void operator delete(void* adr)
	{
		cout << "operator delete()" << endl;
		delete[]adr;
	}

	friend Point& operator--(Point &ref);
	friend const Point operator--(Point &ref,int);
	friend ostream& operator<<(ostream &os, const Point &ref);
	friend int operator+(const int & value, const Point &ref);
};

Point::Point(const Point& cpy)
{
	m_ix = cpy.m_ix;
	m_iy = cpy.m_iy;
}
Point Point::operator+(const Point& cpy)
{
	Point temp;
	temp.m_ix = m_ix + cpy.m_ix;
	temp.m_iy = m_iy + cpy.m_iy;
	return temp;
}
Point Point::operator-(const Point& cpy)
{
	Point temp;
	temp.m_ix = m_ix - cpy.m_ix;
	temp.m_iy = m_iy - cpy.m_iy;
	return temp;
}
Point& Point::operator=(const Point& cpy)
{
	m_ix = cpy.m_ix;
	m_iy = cpy.m_iy;
	return *this;
}
Point& Point::operator+=(const Point& cpy)
{
	m_ix += cpy.m_ix;
	m_iy += cpy.m_iy;
	return *this;
}
int Point::operator [](const int& index) const
{
	switch (index)
	{
	case 0:
		return m_ix;
	case 1:
		return m_iy;
	default:
		return -1;
	}
}
bool Point::operator ==(const Point& cpy) const
{
	if (m_ix == cpy.m_ix && m_iy == cpy.m_iy) return true;
	else return false;
}
int Point::operator+(const int & value)
{
	return m_ix + m_iy + value;
}