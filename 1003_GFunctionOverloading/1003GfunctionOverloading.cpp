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
	friend Point operator+(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main()
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos4(30, 40);
	Point pos5(50, 60);
	Point pos3 = pos1 + pos2 + pos4 + pos5;


	pos3.ShowPosition();
	return 0;
}