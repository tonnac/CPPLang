#include "FruitSeller.h"

void FruitSeller::InitMembers(int price, int num, int money)
{
	Apple_price = price;
	mymoney = money;
	numOfAppels = num;
}

int FruitSeller::SaleApples(int money)
{
	int num = money / Apple_price;
	numOfAppels -= num;
	mymoney += money / Apple_price * Apple_price;
	return num;
}

void FruitSeller::ShowSalesResult()	const
{
	cout << "���� ���: " << numOfAppels << endl;
	cout << "�Ǹ� ����: " << mymoney << endl << endl;
}

int FruitSeller::GetApple_price()	const
{
	return Apple_price;
}