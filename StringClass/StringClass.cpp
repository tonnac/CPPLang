#include "StringClass.h"

STRING::STRING() : Len(0)
{
	m_pCh = NULL;
}
STRING::STRING(const char * src)
{
	int i = 0;
	while (src[i++] != NULL);
	Len = i;
	m_pCh = new char[i];
	for (int k = 0; k < i; k++)
	{
		m_pCh[k] = src[k];
	}
}
STRING::STRING(const STRING & src)
{
	int i = 0;
	while (src.m_pCh[i++] != NULL);
	Len = i;
	m_pCh = new char[i];
	for (int k = 0; k < i; k++)
	{
		m_pCh[k] = src.m_pCh[k];
	}
}

STRING STRING::operator +(const STRING& src)
{
	int i = 0;
	int k = 0;
	char * temp = NULL;
	while (m_pCh[i++] != NULL);
	while (src.m_pCh[k++] != NULL);
	int len = i + k - 1;
	temp = new char[len];
	for (int j = 0; j < i - 1; j++)
	{
		temp[j] = m_pCh[j];
	}
	for (int j = 0; j < k; j++)
	{
		temp[i - 1 + j] = src.m_pCh[j];
	}
	STRING des(temp);
	delete[]temp;
	return des;
}
STRING& STRING::operator +=(const STRING & src)
{
	int i = 0;
	int k = 0;
	while (m_pCh[i++] != NULL);
	while (src.m_pCh[k++] != NULL);
	int len = i + k - 1;
	char * temp = new char[len];
	for (int j = 0; j < i - 1; j++)
	{
		temp[j] = m_pCh[j];
	}
	for (int j = 0; j < k; j++)
	{
		temp[i - 1 + j] = src.m_pCh[j];
	}
	if (m_pCh) { delete[]m_pCh; }
	m_pCh = temp;
	Len = i + k - 1;
	// *this = *this + src;
	return *this;
}
STRING& STRING::operator =(const STRING & src)
{
	int i = 0;
	char * temp = NULL;
	if (m_pCh) { delete[] m_pCh; }
	while ((src.m_pCh[i++]) != NULL);
	temp = new char[i];
	for (int k = 0; k < i; k++)
	{
		temp[k] = src.m_pCh[k];
	}
	m_pCh = temp;
	Len = i;
	return *this;
}
STRING& STRING::operator +(const char * src)
{
	int i = 0;
	int k = 0;
	char * temp = NULL;
	while (m_pCh[i++] != NULL);
	while (src[k++] != NULL);
	int len = i + k - 1;
	temp = new char[len];
	for (int j = 0; j < i - 1; j++)
	{
		temp[j] = m_pCh[j];
	}
	for (int j = 0; j < k; j++)
	{
		temp[i - 1 + j] = src[j];
	}
	if (m_pCh) { delete[]m_pCh; }
	m_pCh = temp;
	Len = i + k -1;
	return *this;
}
bool STRING::operator ==(const STRING & src)
{
	int i = 0;
	int k = 0;
	while (m_pCh[i++] != NULL);
	while (src.m_pCh[k++] != NULL);
	i--, k--;
	if (i != k) { return false; }
	else
	{
		for (int j = 0; j < k;j++)
		{
			if (m_pCh[j] != src.m_pCh[j])
				return false;
		}
		return true;
	}
}


ostream& operator<<(ostream&os, const STRING&src)
{
	os << src.m_pCh << endl;
	return os;
}
ostream& operator<<(ostream&os, const STRING*src)
{
	os << src->m_pCh << endl;
	return os;
}
istream& operator>>(istream&is, STRING&des)
{
	int i = 0;
	char ch[256];
	is >> ch;
	while (ch[i++] != NULL);
	char * src = new char[i];
	for (int k = 0; k < i; k++)
	{
		src[k] = ch[k];
	}
	des.m_pCh = src;
	return is;
}