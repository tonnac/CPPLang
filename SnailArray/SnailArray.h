#pragma once
#include <iostream>

static constexpr int NUM = 43;

class SnailArray
{
public:
	//SnailArray();
	SnailArray(int Column);
	~SnailArray();

	void PrintArray();

private:
	void Init();

private:
	//int mArray[NUM][NUM];

	int **mArray;
	const int mColumn;
};