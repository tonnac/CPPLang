#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPosition() const { cout << xpos << ", " << ypos << endl; }
};

template <class M>
class SmartPtr
{
private:
	M * posptr;
public:
	SmartPtr(M * ptr) : posptr(ptr)
	{}
	Point& operator*() const { return *posptr; }
	Point* operator->() const { return posptr; }
	~SmartPtr() 
	{
		cout << "delete" << endl;
		delete posptr; 
	}
};

