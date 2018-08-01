#include "BoundCheckIntArray.h"

int main()
{
	typedef Point* POINT_PTR;
	BoundCheckIntArray<POINT_PTR> arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(8, 7);

	for (int i = 0;i < arr.GetArrLen();i++)
		cout << arr[i];

	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}