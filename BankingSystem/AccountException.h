#ifndef __ACCOUNT__EXCEPTION_
#define __ACCOUNT__EXCEPTION_
#include "StringClass.h"
#include <iostream>

using namespace std;

class AccountException
{
public:
	virtual void ShowException() const = 0;
};

class WithDrawException : public AccountException
{
private:
	int m_iMoney;
public:
	WithDrawException(int _Money) : m_iMoney(_Money)
	{}
	void ShowException() const
	{
		cout << m_iMoney << "은 잔액보다 많습니다. " << endl;
		cout << "다시 입력해주세요." << endl;
	}
};

class DepositException : public AccountException
{
private:
	int m_iMoney;
public:
	DepositException(int _Money) : m_iMoney(_Money)
	{}
	void ShowException() const
	{
		cout << m_iMoney << "은 잘못된 입력입니다. " << endl;
		cout << "다시 입력해주세요." << endl;
	}
};

#endif
