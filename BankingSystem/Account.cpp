#include "Account.h"


Account::Account(const STRING _name, const int &_Account_number, const int &_Deposit_amount)
	: Name(_name),Account_number(_Account_number), Deposit_amount(_Deposit_amount)
{}
Account::Account() : Name(),Account_number(0) , Deposit_amount(0)
{}
Account::Account(const Account& data) : Name(data.Name),Account_number(data.Account_number) , Deposit_amount(data.Deposit_amount)
{}
Account& Account::operator= (const Account& data)
{
	Name = data.Name;
	Account_number = data.Account_number;
	Deposit_amount = data.Deposit_amount;
	return *this;
}

void Account::DataShow() const
{
	cout << "계좌ID: " << Account_number << endl;
	cout << "이  름: " << Name << endl;
	cout << "입금액: " << Deposit_amount << endl;
}
bool Account::Deposit(const int & money)
{
	if (money <= 0)
	{
		return false;
	}
	Deposit_amount += money;
	return true;
}
bool Account::WithDraw(const int & money)
{
	if (money <= 0 || money > Deposit_amount)
	{
		return false;
	}
	Deposit_amount -= money;
	return true;
}
int Account::GetAccNum(void) const{return Account_number;}
void Account::EditData(const STRING name,const int & AccNum, const int & Money)
{
	Name = name;
	Account_number = AccNum;
	Deposit_amount = Money;
}
int& Account::GetDeposit() { return Deposit_amount; }
const int& Account::GetDeposit() const { return Deposit_amount; }
Account*  Account::GetpNext() const {return pNext;}
void Account::AccountAdd(Account * data)
{
	this->pNext = data;
}

Account::~Account()
{
}