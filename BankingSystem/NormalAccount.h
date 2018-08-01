#pragma once
#include "Account.h"



class NormalAccount : public Account
{
public:
	NormalAccount(const STRING _name, const int &_Account_number,
		const int &_Deposit_amount,const int & _interest) : 
		Account(_name,_Account_number,_Deposit_amount), interestRates(_interest)
	{
		Account::pNext = NULL;
	}
	bool Deposit(const int & money);
	void DataShow() const;
protected:
	const int interestRates;
};

