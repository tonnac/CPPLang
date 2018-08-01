#include "FruitSeller.h"

FruitSeller::FruitSeller(int price, int num, int money) 
	:APPLE_PRICE(price),mymoney(money),numOfAppels(num)
{
}

int FruitSeller::SaleApples(int money)
{
	int num = money / APPLE_PRICE;
	numOfAppels -= num;
	mymoney += money / APPLE_PRICE * APPLE_PRICE;
	return num;
}

void FruitSeller::ShowSalesResult()	const
{
	cout << "���� ���: " << numOfAppels << endl;
	cout << "�Ǹ� ����: " << mymoney << endl << endl;
}

int FruitSeller::GetApple_price()	const
{
	return APPLE_PRICE;
}