#include "TToken.h"

int TToken::m_iCounter = 1;

TValue::TValue(const char * data)
{
	ch = new char[strlen(data) + 1];
	strcpy(ch, data);
	m_pNext = NULL;
}

///////////////////////////TToken///////////////////////////////////



ostream& operator<<(ostream&os, const TValue * data)
{
	TValue * temp = const_cast<TValue*>(data);
	for (int i = 0; i < TToken::m_iCounter; i++)
	{
		os << temp->ch << endl;
		temp = temp->m_pNext;
	}
	return os;
}

TToken::TToken(const char * data)
{
	char * ccdata = const_cast<char*>(data);
	char * temp = strtok(ccdata, " ");
	m_pTValue = new TValue(temp);
	TValue * sv = m_pTValue;
	while ((temp = strtok(NULL, " "))!= NULL)
	{	
		m_iCounter++;
		sv->m_pNext = new TValue(temp);
		sv = sv->m_pNext;
	}
}

TToken::~TToken()
{
	TValue * temp = m_pTValue;
	TValue * temp1 = m_pTValue;
	for (int i = 0; i < m_iCounter; i++)
	{
		temp1 = temp1->m_pNext;
		delete temp;
		temp = temp1;
	}
}

