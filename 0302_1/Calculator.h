#pragma once
#include <iostream>
using namespace std;
class Calculator
{
public:
	void Init();
	double Add(double x, double y);
	double Div(double x, double y);
	double Min(double x, double y);
	double Mul(double x, double y);
	void ShowOpCount();
private:
	double a;
	double b;
	int AddCount;
	int DivCount;
	int MinCount;
	int MulCount;
};

