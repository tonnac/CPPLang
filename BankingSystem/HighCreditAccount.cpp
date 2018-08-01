#include "HighCreditAccount.h"

bool HighCreditAccount::Deposit(const int & money)
{
	int & a_Deposit = Account::GetDeposit();
	if (money <= 0)
	{
		return false;
	}
	Account::Deposit(a_Deposit*(double)Credit / 100);
	NormalAccount::Deposit(money);
	return true;
}
void HighCreditAccount::DataShow() const
{
	NormalAccount::DataShow();
	cout << "신용등급: " << Credit << "%" << endl;
}