#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>
#pragma comment (lib,"winmm.lib")
class Landing
{
	friend int main();
public:
	Landing(int Height) : m_iHeight(Height)
	{
		try {
			arr = new int*[Height];
			for (int i = 0; i < Height; ++i)
			{
				arr[i] = new int[4];
			}
		}
		catch (std::bad_alloc &bad)
		{
			std::cout << bad.what() << std::endl;
		}
		Init();
	}
	~Landing()
	{
		for (int i = 0; i < m_iHeight; ++i)
		{
			delete[]arr[i];
		}
		delete[]arr;
	}
public:
	int					MaxValue()
	{
		for (int i = 0; i < WIDTH; ++i)
		{
			rarr.push_back(Searching(i));
		}

		std::sort(rarr.begin(), rarr.end());
		return rarr.at(3);
	}
	void				Print()
	{
		for (int i = 0; i < m_iHeight; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{
				if (j != 0)
				{
					std::cout << ", ";
				}
				std::cout << arr[i][j];
			}
			std::cout<<std::endl;
		}
	}
private:
	int					Searching(int iStart)
	{
		int start = iStart;
		int Result = arr[0][start];
		for (int i = 0; i < m_iHeight - 1; ++i)
		{
			int MaxIndex = MaxIndexSearch(i + 1);
			int SecondIndex = SecondIndexSearch(i + 1);
			if (start == MaxIndex)
			{
				start = SecondIndex;
			}
			else
				start = MaxIndex;
			Result += arr[i + 1][start];
		}
		return Result;
	}
	int					MaxIndexSearch(int iHeight)
	{
		int MaxIndex = 0;
		for (int i = 1; i < WIDTH; ++i)
		{
			if (arr[iHeight][i] >= arr[iHeight][MaxIndex])
			{
				MaxIndex = i;
			}
		}
		return MaxIndex;
	}
	int					SecondIndexSearch(int iHeight)
	{
		int MaxIndex = MaxIndexSearch(iHeight);
		int SecondIndex = 0;
		if (MaxIndex == 0)
		{
			SecondIndex = 1;
		}
		for (int i = 1; i < WIDTH; ++i)
		{
			if (i == MaxIndex)
			{
				continue;
			}
			if (arr[iHeight][i] >= arr[iHeight][SecondIndex])
			{
				SecondIndex = i;
			}
		}
		return SecondIndex;
	}
private:
	void				Init()
	{
		for (int i = 0; i < m_iHeight; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{
				arr[i][j] = rand() % 8;
			}
		}
	}
private:
	std::vector<int>	rarr;
	static const int	WIDTH = 4;
	int					m_iHeight;
	int**				arr;
};