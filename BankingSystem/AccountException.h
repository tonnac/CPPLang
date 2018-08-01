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
		cout << m_iMoney << "�� �ܾ׺��� �����ϴ�. " << endl;
		cout << "�ٽ� �Է����ּ���." << endl;
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
		cout << m_iMoney << "�� �߸��� �Է��Դϴ�. " << endl;
		cout << "�ٽ� �Է����ּ���." << endl;
	}
};

#endif
