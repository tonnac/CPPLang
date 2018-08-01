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
	void Init(int a, int b, double c, int d, int e, double f);
	void ShowRingInfo();
};