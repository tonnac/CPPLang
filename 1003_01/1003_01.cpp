#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend ostream& operator << (ostream & os, const Point & pos1);
	friend istream& operator >> (istream & is, Point & pos1);
	
};
istream& operator >> (istream & is, Point & pos1)
{
	is >> pos1.xpos >> pos1.ypos;
	return is;
}
ostream& operator << (ostream & os, const Point & pos1)
{
	os << '[' << pos1.xpos << " ," << pos1.ypos << ']' << endl;
	return os;
}

int main()
{
	Point pos1;
	cin >> pos1;
	cout << pos1;
	Point pos2(101, 303);
	cout << pos2;
	return 0;
}