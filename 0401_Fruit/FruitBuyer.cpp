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
		cout << "�߸��� �ݾ� �Է�.";
		return false;
	}
	mymoney -= money / seller.GetApple_price() * seller.GetApple_price();
	numofappels += seller.SaleApples(money);
}
void FruitBuyer::ShowBuyResult()	const
{
	cout << "���� �ܾ�: " << mymoney << endl;
	cout << "��� ����: " << numofappels << endl << endl;
}