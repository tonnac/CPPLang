#pragma once
#include <iostream>
using namespace std;

class STRING
{
private:
	size_t Len;
	char * m_pCh;
public:
	STRING();
	STRING(const char * src);
	STRING(const STRING & src);
	~STRING() { if(m_pCh!=NULL) delete[]m_pCh; }
public:
	STRING operator +(const STRING& src);
	STRING& operator +=(const STRING & src);
	STRING& operator =(const STRING & src);
	STRING& operator +(const char * src);
public:
	bool operator ==(const STRING & src);
public:
	friend ostream& operator<<(ostream&, const STRING&);
	friend ostream& operator<<(ostream&, const STRING*);
	friend istream& operator>>(istream&, STRING&);

};