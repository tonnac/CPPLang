#include "FruitBuyer.h"


void FruitBuyer::InitMembers(int money)
{
	mymoney = money;
	numofappels = 0;
}
bool FruitBuyer::BuyAppels(FruitSeller &seller, int money)
{
	if (money <= 0)
	{
		cout << "잘못된 금액 입력.";
		return false;
	}
	mymoney -= money / seller.GetApple_price() * seller.GetApple_price();
	numofappels += seller.SaleApples(money);
}
void FruitBuyer::ShowBuyResult()	const
{
	cout << "현재 잔액: " << mymoney << endl;
	cout << "사과 개수: " << numofappels << endl << endl;
}