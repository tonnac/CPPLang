#pragma once
#include <iostream>

class QUESTION_1
{
public:
	void Main();
	QUESTION_1(int len = 5);
	~QUESTION_1();
private:
	int Sumarray();
	void input();
	int arrlen;
	int * arr;
};

class QUESTION_2
{
public:
	void Main();	
private:
	void input();
	void output();
	char name[100];
	char Phone[100];
};

class QUESTION_3
{
public:
	void Main();
private:
	void input();
	void output();
	int m_iValue;
};

class QUESTION_4
{
public:
	QUESTION_4();
	void Main();
	void ShowPay();
private:
	bool inputSales();
	int m_iPay;
	int m_iBonus;
	int m_iSales;
};