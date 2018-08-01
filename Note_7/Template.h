#pragma once
#include <iostream>

using namespace std;

template <typename A>
A add(A n1, A n2)
{
	cout << "T(T n1, T n2)" << endl;
	return n1 + n2;
}

int add(int num1, int num2)
{
	cout << "Add(int num1, int num2)" << endl;
	return num1 + num2;
}

double add(double num1, double num2)
{
	cout << "add(double num1, double num2)" << endl;
	return num1 + num2;
}
