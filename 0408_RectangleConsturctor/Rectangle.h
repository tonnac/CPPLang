#pragma once

#include "Point.h"

class Rectangle
{
private:
	Point upleft;
	Point lowright;

public:
	Rectangle(const int & x1, const int & y1, const int & x2, const int & y2);
	bool InitMembers(const Point &ul, const Point &lr);
	void ShowRecInfo() const;
};