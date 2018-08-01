#include "BoundCheckIntArray.h"

int main()
{
	BoundCheckIntArray<Point> arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];

	return 0;
}