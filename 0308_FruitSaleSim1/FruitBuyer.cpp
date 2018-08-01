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
	cout << "���� �ܾ�: " << mymoney << endl;
	cout << "��� ����: " << numofappels << endl << endl;
}