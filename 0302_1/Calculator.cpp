#include "Calculator.h"

void Calculator::Init()
{
	a = 0;
	b = 0;
	AddCount = 0;
	MinCount = 0;
	DivCount = 0;
	MulCount = 0;
}
double Calculator::Add(double x, double y)
{
	AddCount++;
	return x + y;
}
double Calculator::Div(double x, double y)
{
	DivCount++;
	if (y == 0) return-1;
	return x / y;
}
double Calculator::Min(double x, double y)
{
	MinCount++;
	return x - y;
}
double Calculator::Mul(double x, double y)
{
	MulCount++;
	return x * y;
}
void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << AddCount << " " << "»¬¼À: " << MinCount << " " << "°ö¼À: " << MulCount << " " << "³ª´°¼À: " << DivCount << endl;
}
