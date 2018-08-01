#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
public:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

template <class T>
class BoundCheckIntArray
{
private:
	T * arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& data) {}
	BoundCheckIntArray& operator =(const BoundCheckIntArray& data) {}
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new T[len];
	}
	T& operator[] (int idx)
	{
		try
		{
			if (idx < 0 || idx >= arrlen)
			{
				throw false;
			}
			return arr[idx];
		}
		catch (bool expn)
		{
			if (expn == false)
			{
				cout << "²¨Á®" << endl;
				exit(1);
			}
		}
	}
	T& operator[] (int idx) const
	{
		try
		{
			if (idx < 0 || idx >= arrlen)
			{
				throw false;
			}
			return arr[idx];
		}
		catch (bool expn)
		{
			if (expn == false)
			{
				cout << "²¨Á®" << endl;
				exit(1);
			}
		}
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};
