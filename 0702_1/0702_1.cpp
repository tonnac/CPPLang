#include <iostream>

using namespace std;

class Rectangle
{
private:
	int width;
	int height;
public:
	Rectangle(int _width) : width(_width), height(_width)
	{}
	Rectangle(int _width, int _height) : width(_width), height(_height)
	{}
	void ShowAreaInfo() const
	{
		cout << "¸éÀû: " << width * height << endl;
	}
};

class Square : public Rectangle
{
private:
public:
	Square(int _width) : Rectangle(_width)
	{}
};

int main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
}