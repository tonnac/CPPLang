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
	template <class PL>
	friend void Swaaaap(Point & data);
};

template <class PL>
void Swaaaap(Point & data)
{
	int temp;
	temp = data.xpos;
	data.xpos = data.ypos;
	data.ypos = temp;
}

int main()
{
	Point a1(3, 5);
	Swaaaap<int>(a1);
	a1.ShowPosition();
}