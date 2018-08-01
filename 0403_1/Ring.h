#pragma once
#include "Point.h"

class Ring
{
private:
	Point inner_circle;
	double inner_circlerad;
	Point outter_circle;
	double outter_circlerad;
public:
	Ring(const int &a, const int &b, const double &c, const int &d, const int &e, const double &f)
		: inner_circle(a, b), inner_circlerad(c), outter_circle(d, e), outter_circlerad(f)
	{
	}
//	void Init(int a, int b, double c, int d, int e, double f);
	void ShowRingInfo();
};