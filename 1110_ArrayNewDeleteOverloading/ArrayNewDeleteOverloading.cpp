#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos, zpos;
public:
	Point(int x = 0, int y = 0, int z = 0) : xpos(x), ypos(y), zpos(z) {}
	friend ostream& operator<<(ostream& os, const Point& pos);
	static void * operator new (size_t size)
	{
		cout << "operator new : " << size << endl;
		void * adr = new char[size];
		return adr;
	}
	void * operator new[] (size_t size)
	{
		cout << "operator new[] : " << size << endl;
		void * adr = new char[size];
		return adr;
	}
	static void operator delete (void * adr)
	{
		cout << "operator delete ()" << endl;
		delete[]adr;
	}
	void operator delete[] (void * adr)
	{
		cout << "operator delete[] ()" << endl;
		delete[]adr;
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ", " << pos.zpos << ']' << endl;
	return os;
}

int main()
{
	Point * ptr = new Point(1, 2, 3);
	Point * arr = new Point[3];
	delete ptr;
	delete[]arr;

	return 0;
}