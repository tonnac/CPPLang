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
	Point operator+(const Point &pos1);
	Point& operator+=(const Point &pos1);
	const Point& operator-=(const Point &pos1);
	/*friend Point operator+(const Point &pos1, const Point &pos2);*/
	friend Point operator-(const Point &pos1, const Point &pos2);
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
};

//Point operator+(const Point &pos1, const Point &pos2)
//{
//	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
//	return pos;
//}
Point Point::operator+(const Point &pos1)
{
	Point pos;
	pos.xpos = xpos + pos1.xpos;
	pos.ypos = ypos + pos1.ypos;
	return pos;
}
Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}
bool operator==(const Point& pos1, const Point& pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos) { return true; }
	else return false;
}
bool operator!=(const Point& pos1, const Point& pos2)
{
	if (pos1 == pos2) return false;
	else return true;
}


Point& Point::operator+=(const Point &pos1)
{
	xpos += pos1.xpos;
	ypos += pos1.ypos;
	return *this;
}
const Point& Point::operator-=(const Point &pos1)
{
	xpos -= pos1.xpos;
	ypos -= pos1.ypos;
	return *this;
}



int main()
{
	Point a(10, 10);
	Point b(10, 10);
	Point c(20, 20);
	Point e(10, 10);
	Point f(10, 10);
	Point g(30, 30);
	Point d;
	d = a + b + c + e + f + g;
	d.ShowPosition();

	return 0;
}