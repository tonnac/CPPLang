#include "NormalAccount.h"

bool NormalAccount::Deposit(const int & money)
{
	int & a_Deposit = Account::GetDeposit();
	if (money <= 0)
	{
		return false;
	}
	Account::Deposit(a_Deposit*(double)interestRates/100);
	Account::Deposit(money);
	return true;
}
void NormalAccount::DataShow() const
{
	Account::DataShow();
	cout << "ÀÌÀÚÀ²: " << interestRates << endl;
}