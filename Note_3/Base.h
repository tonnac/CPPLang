#pragma once
#include <iostream>
using namespace std;

class Base
{
public:
	char * ch;
	int a;
public:
	Base(char * _ch = NULL, int n = 0) : a(n)
	{
	}
	virtual void Func()
	{
		cout << "A" << endl;
	}
};