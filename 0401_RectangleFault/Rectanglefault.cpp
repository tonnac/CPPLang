#include <iostream>

using namespace std;

class Point
{
public:
	int x;
	int y;
};

class Rectangle
{
public:
	Point upleft;
	Point lowright;
public:
	void ShowRecInfo()
	{
		cout << "좌 상단: " << '[' << upleft.x << ", ";
		cout << upleft.y << ']' << endl;
		cout << "우 하단: " << '[' << lowright.x << ", ";
		cout << lowright.y << ']' << endl;
	}
};

int main()
{
	Point pos1 = { -2,4 };
	Point pos2 = { 5, 9 };
	Rectangle rec = { pos2,pos1 };
	rec.ShowRecInfo();
}