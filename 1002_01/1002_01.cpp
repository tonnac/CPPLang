#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++()
	{
		xpos++;
		ypos++;
		return *this;
	}
	Point operator-()
	{
		Point ret;
		ret.xpos = xpos * (-1);
		ret.ypos = ypos * (-1);
		return ret;
	}
	friend Point& operator-- (Point &ref);
	friend Point& operator ~ (Point &ref);
};

Point& operator ~(Point&ref)
{
	ref.xpos ^= ref.ypos;
	ref.ypos ^= ref.xpos;
	ref.xpos ^= ref.ypos;
	return ref;
}
Point& operator-- (Point&ref)
{
	ref.xpos--;
	ref.ypos--;
	return ref;
}

int main(void)
{
	Point pos1(1, 2);
	Point pos2 = -pos1;
	~pos2;
	pos2.ShowPosition();
	return 0;
}