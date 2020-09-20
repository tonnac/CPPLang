#include "Floyd.h"

void ShowGraph(ptrarr ptr, const int& width)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (j != 0)
			{
				std::cout << "\t";
			}
			std::cout << ptr[i][j];
		}
		std::cout << std::endl;
	}
}

void Floyd::CreateFloyd(ptrarr ptr)
{
	for (int i = 3; i >= 0; --i)
	{
		for (int j = 3; j >= 0; --j)
		{
			for (int k = 3; k >= 0; --k)
			{
				if (ptr[j][k] > ptr[j][i] + ptr[i][k])
				{
					ptr[j][k] = ptr[j][i] + ptr[i][k];
				}
			}
		}
	}
}