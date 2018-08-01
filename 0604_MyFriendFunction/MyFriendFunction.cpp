#include <iostream>

using namespace std;

class Point;

class PointOP
{
private:
	int opcnt;
public:
	PointOP() : opcnt(0)
	{}

	Point PointAdd(const Point&, const Point&);
	Point PointSub(const Point&, const Point&);

	~PointOP()
	{
		cout << "Operation times: " << opcnt << endl;
	}
};

class Point
{
private:
	int x;
	int y;
public:
	Point(const int& xpos, const int &ypos) : x(xpos), y(ypos)
	{}
	Point();
	friend Point PointOP::PointAdd(const Point&, const Point&);
	friend Point PointOP::PointSub(const Point&, const Point&);
	friend void ShowPointPos(const Point&);
};

class Test
{
private:
	Point p1;
	Point p2;
public:
	Test(int a, int b, int c, int d) : p1(a,b),p2(c,d)
	{}
	~Test()
	{
		cout << "Destruct" << endl;
	}
	Point& Getp1()
	{
		return p1;
	}
};
Point::Point()
{}
Point PointOP::PointAdd(const Point&pnt1, const Point&pnt2)
{
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}
Point PointOP::PointSub(const Point&pnt1, const Point&pnt2)
{
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}
int main()
{
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;
	Test pp(5, 6, 7, 8);
	Point p3;
	p3 = pp.Getp1();

	ShowPointPos(p3);
	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));
}

void ShowPointPos(const Point& pos)
{
	cout << "x: " << pos.x << ", ";
	cout << "y: " << pos.y << endl;
}