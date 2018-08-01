#pragma once
#include "Employee.h"

class PermanentWorker : public Employee
{
public:
	PermanentWorker(const char * name, int money) 
		: Employee(name), salary(money)
	{
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
private:
	int salary;
};

