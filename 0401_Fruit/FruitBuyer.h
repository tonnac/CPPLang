#pragma once
#include "FruitSeller.h"
#include <iostream>

using namespace std;

class FruitBuyer
{
public:
	void InitMembers(int money);
	bool BuyAppels(FruitSeller &seller, int money);
	void ShowBuyResult()	const;
private:
	int mymoney;
	int numofappels;
};

