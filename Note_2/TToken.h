#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "TValue.h"
#include <iostream>
#include <cstring>
#define SPACE " "

class TValue;

class TToken
{
private:
	TValue * tValue;
	int iCounter;
public:
	TToken(char * data);
	~TToken();
};

