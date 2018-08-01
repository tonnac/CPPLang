#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(const int&x, const int &y) : xpos(x), ypos(y)
	{
	}
	//void Init(int x, int y)
	//{
	//	xpos = x;
	//	ypos = y;
	//}
	void ShowPointInfor() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};