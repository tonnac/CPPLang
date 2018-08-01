#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class TToken;

class TValue
{
private:
	char * ch;
	TValue * m_pNext;
	TValue(const char * data);
	~TValue() { delete[]ch; }
	friend class TToken;
	friend ostream& operator<<(ostream&os, const TValue * data);
};


class TToken
{
private:
	static int m_iCounter;
	TValue * m_pTValue;
public:
	TValue * GetTValue() { return m_pTValue; }
	TToken() : m_pTValue(NULL)
	{}
	TToken(const char * data);
	~TToken();
	friend ostream& operator<<(ostream& os, const TValue * data);
};

