#pragma once
#include <iostream>

using ptrarr = int(*)[4];

void ShowGraph(ptrarr ptr, const int& width);

class Floyd
{
public:
	static void CreateFloyd(ptrarr ptr);
};