#include <iostream>
using namespace std;

template <typename K>
class Point
{
private:
	K xpos, ypos;
public:
	Point(K x = 0, K y = 0);
	void ShowPosition() const;
	friend Point<int> operator+(const Point<int>&, const Point<int>&);
	friend ostream& operator<<(ostream&, const Point<K>&);
};
template <typename K>
Point<K>::Point(K x, K y) : xpos(x), ypos(y)
{}
template <typename K>
void Point<K>::ShowPosition() const
{
	cout << xpos << ", " << ypos << endl;
}

Point<int> operator+(const Point<int>& a1, const Point<int>& a2)
{
	return Point<int>(a1.xpos + a2.xpos, a1.ypos + a2.ypos);
}

template <typename K>
ostream& operator<<(ostream&os, const Point<K>& src)
{
	os << src.xpos << ", " << src.ypos << endl;
	return os;
}

int main()
{
	Point<int> a2(1.2, 3.4);
	Point<int> a3(1.2, 3.4);
	a2 + a3;
	cout << a2;
	return 0;
}