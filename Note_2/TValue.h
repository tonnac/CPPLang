#pragma once
#include "TToken.h"



class TValue
{
private:
	char * pChar;
	TValue * pNext;
	~TValue();
	friend class TToken;
	TValue(char * str);
public:
	
};

