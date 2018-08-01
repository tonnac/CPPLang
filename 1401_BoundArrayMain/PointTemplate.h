#ifndef __POINT_TEMPLATE_H_
#define __POINT_TEMPLATE_H_
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
};
template <typename K>
Point<K>::Point(K x,K y): xpos(x), ypos(y)
{}
template <typename K>
void Point<K>::ShowPosition() const
{
	cout << xpos << ", " << ypos << endl;
}
#endif