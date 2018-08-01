#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int a=0, int b=0)
	{
		xpos = a;
		ypos = b;
	}
	friend Point& PntAdder(const Point& p1, const Point& p2);
};


Point& PntAdder(const Point& p1, const Point& p2);

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point * New = new Point;
	New->xpos = p1.xpos + p2.xpos;
	New->ypos = p1.ypos + p2.ypos;

	return *New;
}


int main()
{
	Point * A1 = new Point(10, 20);
	Point * A2 = new Point(30, 40);
	Point * A3 = &(PntAdder(*A1, *A2));

	return 0;
}