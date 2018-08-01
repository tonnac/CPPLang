#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class Printer
{
	enum{STRLEN = 20};
public:
	void SetString(const char * save);
	void ShowString();
private:
	char string[STRLEN];
};

