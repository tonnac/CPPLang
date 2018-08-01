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
};

int main()
{
	Point pos(1, 2);
	Point cpy;
	cpy = pos * 3;
	cpy.ShowPosition();

	cpy = pos * 3 * 2932;
	cpy.ShowPosition();
	return 0;
}