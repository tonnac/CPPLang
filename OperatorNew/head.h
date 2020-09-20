#pragma once
#include <iostream>
using namespace std;
class A
{
public:
	void* operator new(size_t sz, const char* file, int b);
	void operator delete(void* ptr, const char* file, int b);
};



//int* reter()
//{
//	int a = 4;
//	return &a;
//}