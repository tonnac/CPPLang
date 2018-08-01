#pragma once


class QUESTION_1
{
public:
	void Plus(int & ref);
	void Change(int & ref);
};

class QUESTION_3
{
public:
	void Main();
	
	QUESTION_3(int a, int b);
private:
	void Swap();
	int num1;
	int num2;
	int * ptr1;
	int * ptr2;
};