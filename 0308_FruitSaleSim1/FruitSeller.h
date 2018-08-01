#pragma once
#include <iostream>

using namespace std;

class FruitSeller
{

public:
	void InitMembers(int price, int num, int money);
	int SaleApples(int money);
	void ShowSalesResult();
private:
	int Apple_price;
	int numOfAppels;
	int mymoney;
};

