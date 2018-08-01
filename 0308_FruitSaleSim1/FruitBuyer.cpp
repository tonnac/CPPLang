#include "FruitBuyer.h"


void FruitBuyer::InitMembers(int money)
{
	mymoney = money;
	numofappels = 0;
}
void FruitBuyer::BuyAppels(FruitSeller &seller, int money)
{
	mymoney -= money;
	numofappels += seller.SaleApples(money);
}
void FruitBuyer::ShowBuyResult()
{
	cout << "현재 잔액: " << mymoney << endl;
	cout << "사과 개수: " << numofappels << endl << endl;
}