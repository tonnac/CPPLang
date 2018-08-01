#include <iostream>
#include "Point.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	Point pos1(-2, 4);
	Point pos2(2, 4);
	Point pos3(5, 9);
	Rectangle rec(-2, 4, 5, 9);
	Rectangle rec1(2, 4, 5, 9);
	//if (!rec.InitMembers(pos2, pos1))
	//	cout << "직사각형 초기화 실패" << endl;

	//if (!rec.InitMembers(pos1, pos2))
	//	cout << "직사각형 초기화 실패" << endl;

	rec1.ShowRecInfo();

}