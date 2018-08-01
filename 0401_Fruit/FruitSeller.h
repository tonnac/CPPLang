#pragma once
#include <iostream>

using namespace std;

class FruitSeller
{

public:
	void InitMembers(int price, int num, int money);
	int SaleApples(int money);
	void ShowSalesResult()	const;
	int GetApple_price()	const;
private:
	int Apple_price;
	int numOfAppels;
	int mymoney;
};

