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
	mymoney += money;
	return num;
}

void FruitSeller::ShowSalesResult()
{
	cout << "���� ���: " << numOfAppels << endl;
	cout << "�Ǹ� ����: " << mymoney << endl << endl;
}
