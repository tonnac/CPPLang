#pragma once
#include "BoundCheckAccountArray.h"
#include "AccountException.h"

class MainMenu
{
public:
	void Account_Type();
	void title();
	void Normal_Account_create();
	void HighCredit_Account_create();
	void Deposit() const;
	void Withdraw() const;
	void Print_All() const;
	void RandomCreate();
	Account* SearchAcc(const int &num) const;
public:
private:
	BoundCheckptrArray<Account> arr;
	/*int AccNum;
	int Money;
	int Number;*/
};