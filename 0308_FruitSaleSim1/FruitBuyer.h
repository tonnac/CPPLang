#pragma once
#include "FruitSeller.h"
#include <iostream>

using namespace std;

class FruitBuyer
{
public:
	void InitMembers(int money);
	void BuyAppels(FruitSeller &seller, int money);
	void ShowBuyResult();
private:
	int mymoney;
	int numofappels;
};

