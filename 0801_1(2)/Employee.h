#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

enum RISK_LEVEL { RISK_C = 1, RISK_B = 2, RISK_A = 3 };

using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(const char * name)
	{
		strcpy_s(this->name,100, name);
	}
	void ShowYourName() const
	{
		cout << "Name: " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};