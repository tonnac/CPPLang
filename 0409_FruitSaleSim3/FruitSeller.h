#pragma once
#include <iostream>

using namespace std;

class FruitSeller
{

public:
	FruitSeller(int price,int num, int money);
	int SaleApples(int money);
	void ShowSalesResult()	const;
	int GetApple_price()	const;
private:
	const int APPLE_PRICE;
	int numOfAppels;
	int mymoney;
};

