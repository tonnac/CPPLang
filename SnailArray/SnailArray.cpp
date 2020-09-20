#include "SnailArray.h"


//SnailArray::SnailArray()
//{
//	Init();
//}

SnailArray::SnailArray(int Column) :
	mColumn(Column)
{
	mArray = new int*[mColumn];
	for (int i = 0; i < mColumn; ++i)
	{
		mArray[i] = new int[mColumn];
	}

	Init();
}

SnailArray::~SnailArray()
{
	for (int i = 0; i < mColumn; ++i)
	{
		delete[] mArray[i];
		mArray[i] = nullptr;
	}
	delete[] mArray;
	mArray = nullptr;
}

void SnailArray::Init()
{
	int i = 0;
	int j = -1;
	int Value = 0;
	int Multiply = 1;
	int c = mColumn;

	/*while (Value <= NUM * NUM)
	{
		for (int a = 0; a < c; ++a)
		{
			mArray[i][j] = Value++;
			j += Multiply;
		}

		if (Value >= NUM * NUM)
			break;

		for (int b = 0; b < c; ++b)
		{
			mArray[i][j] = Value++;
			i += Multiply;
		}

		Multiply *= -1;
		if (Multiply > 0)
		{
			i += 1;
			j += 1;
			c -= 2;
			if (c == 0)
				c = 1;
		}
	}*/
	while (Value < mColumn * mColumn)
	{
		for (int a = 0; a < c; ++a)
		{
			j += Multiply;
			mArray[i][j] = Value++;
		}
		c -= 1;
		for (int a = 0; a < c; ++a)
		{
			i += Multiply;
			mArray[i][j] = Value++;
		}
		Multiply *= -1;
	}

}

void SnailArray::PrintArray()
{
	for (int i = 0; i < mColumn; ++i)
	{
		for (int j = 0; j < mColumn; ++j)
		{
			if (j != 0)
				std::cout << " ";
			printf("%3d", mArray[i][j]);
		}
		std::cout << std::endl;
	}
}