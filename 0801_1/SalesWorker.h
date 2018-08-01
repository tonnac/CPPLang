#pragma once
#include "Employee.h"
#include "PermanentWorker.h"

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;
	double bonusratio;
public:
	SalesWorker(const char * name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusratio(ratio)
	{}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult*bonusratio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};