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
	friend Point& operator-- (Point &ref);
};

Point& operator-- (Point&ref)
{
	ref.xpos--;
	ref.ypos--;
	return ref;
}

int main(void)
{
	Point pos1(1, 2);
	++pos1;
	pos1.ShowPosition();
	--pos1;
	pos1.ShowPosition();

	++(++pos1);
	pos1.ShowPosition();
	--(--pos1);
	pos1.ShowPosition();
	return 0;
}