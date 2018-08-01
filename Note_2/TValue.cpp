#include "TValue.h"


TValue::TValue(char * str)
{
	pChar = new char[strlen(str) + 1];
	strcpy(pChar, str);
	pNext = NULL;
}


TValue::~TValue()
{
	delete[]pChar;
}
