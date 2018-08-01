#pragma once
#include "NormalAccount.h"



class HighCreditAccount : public NormalAccount
{
public:
	HighCreditAccount(const STRING _name, const int &_Account_number,
		const int &_Deposit_amount, const int & _interest, const HighCredit type)
		: NormalAccount(_name, _Account_number, _Deposit_amount, _interest),
		Credit(type)
	{
		Account::pNext = NULL;
	}
	bool Deposit(const int & money);
	void DataShow() const;
private:
	const HighCredit Credit;
};

