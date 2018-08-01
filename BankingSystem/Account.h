#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "StringClass.h"
#include <cstring>
#include <cstdlib>
#include <ctime>


enum Accounttype { NORMAL = 1, HIGH };
enum HighCredit { C = 2, B = 4, A = 7 };
enum Menu { ACCOUNT_TYPE = 1, DEPOSIT, WITHDRAW, PRINT_ALL_ACCOUNT, RANDOM_CREATE, EXIT };

using namespace std;

class Account
{
public:
public:
	bool WithDraw(const int & money);
	virtual bool Deposit(const int & money) = 0;
	virtual void DataShow() const;
	void EditData(const STRING name, const int & AccNum, const int & Money);
	int GetAccNum(void) const;
	int& GetDeposit();
	const int& GetDeposit() const;
	Account* GetpNext() const;
public:
	void AccountAdd(Account * data);
	Account(const STRING _name, const int &_Account_number, const int &_Deposit_amount);
	Account();
	Account& operator= (const Account& data);
	Account(const Account& data);
	~Account();
private:
	STRING Name;
	int Account_number;
	int Deposit_amount;
protected:
	Account * pNext;
};