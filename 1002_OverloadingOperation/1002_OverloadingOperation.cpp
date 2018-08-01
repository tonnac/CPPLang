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
	Point operator+(const Point &ref)
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos4(30, 40);
	Point pos5(50, 60);
	Point pos3 = pos1 + pos2 + pos3 + pos4;
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos4.ShowPosition();
	pos5.ShowPosition();
	pos3.ShowPosition();

	return 0;
}