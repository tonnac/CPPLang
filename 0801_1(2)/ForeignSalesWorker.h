#pragma once
#include "SalesWorker.h"

class ForeignSalesWorker : public SalesWorker
{
private:
	RISK_LEVEL type;
public:
	ForeignSalesWorker(const char * name, int money, double ratio, RISK_LEVEL _type)
		:SalesWorker(name, money, ratio), type(_type)
	{}
	int GetPay() const
	{
		return (int)(SalesWorker::GetPay())*(1+(double)type/10);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};