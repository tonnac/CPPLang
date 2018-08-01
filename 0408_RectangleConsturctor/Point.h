#pragma once

using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	Point(const int &x, const int &y);
	bool InitMembers(int xpos, int ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};