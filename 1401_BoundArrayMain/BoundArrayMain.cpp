#include <iostream>
#include "PointTemplate.h"
#include "ArrayTemplate.h"
using namespace std;

int main()
{
	BoundCheckArray<Point<int>> oarr1(3);
	oarr1[0] = Point<int>(3, 4);
	oarr1[1] = Point<int>(1, 2);
	oarr1[2] = Point<int>(5, 6);

	for (int i = 0; i < oarr1.GetArrLen(); i++)
		oarr1[i].ShowPosition();


	BoundCheckArray<Point<double>> oarr3(3);
	oarr3[0] = Point<double>(3.14, 3.14);
	oarr3[1] = Point<double>(4.14, 4.14);
	oarr3[2] = Point<double>(6.14, 5.14);

	for (int i = 0; i < oarr1.GetArrLen(); i++)
		oarr3[i].ShowPosition();

	BoundCheckArray<Point<int>*> oarr2(3);
	oarr2[0] = new Point<int>(30, 40);
	oarr2[1] = new Point<int>(31, 41);
	oarr2[2] = new Point<int>(32, 43);

	for (int i = 0; i < oarr1.GetArrLen(); i++)
		oarr2[i]->ShowPosition();


	return 0;
}