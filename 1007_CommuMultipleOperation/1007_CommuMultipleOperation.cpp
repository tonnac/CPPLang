#include <iostream>

using namespace std;

class Point
{
private:
	int xpos;
public:
	int ypos;
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator*(int times)
	{
		Point pos(xpos*times, ypos*times);
		return pos;
	}
	friend Point operator*(int times, const Point & ref);
};

Point operator*(int times, const Point & ref)
{
	Point ret(times*ref.xpos, times*ref.ypos);
	return ret;
}

int main()
{
	Point pos(1, 2);
	Point cpy;
	cpy = pos * 3;
	cpy.ShowPosition();

	cpy = 2932 * cpy * 123;
	cpy.ShowPosition();
	return 0;
}