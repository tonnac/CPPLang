#include <iostream>
#include <string>
#include "head.h"
int k = 0;

struct ptr
{
	std::string _file;
	int			line;
};

ptr g_ptr;

void* A::operator new(size_t sz, const char* file, int b)
{
	g_ptr._file = file;
	g_ptr.line = b;
	void* pfs = ::operator new(sz);
	return pfs;
}
void A::operator delete(void* ptr, const char* file, int b)
{
	return ::operator delete(ptr);
}
