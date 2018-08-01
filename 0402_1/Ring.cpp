#include "Ring.h"

void Ring::Init(int a, int b, double c, int d, int e, double f)
{
	inner_circle.Init(a, b);
	inner_circlerad = c;
	outter_circle.Init(d, e);
	outter_circlerad = f;
}
void Ring::ShowRingInfo()
{
	cout << "Inner Circle Info..." << endl;
	cout << "radius: " << inner_circlerad << endl;
	inner_circle.ShowPointInfor();
	cout << "Outter Circle Info..." << endl;
	cout << "radius: " << outter_circlerad << endl;
	outter_circle.ShowPointInfor();
}