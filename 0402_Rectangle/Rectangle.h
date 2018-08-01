#pragma once

#include "Point.h"

class Rectangle
{
private:
	Point upleft;
	Point lowright;

public:
	bool InitMembers(const Point &ul, const Point &lr);
	void ShowRecInfo() const;
};