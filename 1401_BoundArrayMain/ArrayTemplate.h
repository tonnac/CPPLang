#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_
#include <iostream>
#include <cstdlib>
using namespace std;


template <class W>
class BoundCheckArray
{
private:
	W * arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& data) {}
	BoundCheckArray& operator=(const BoundCheckArray& data) {}

public:
	BoundCheckArray(int len);
	W& operator[] (int idx);
	W operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <class W>
BoundCheckArray<W>::BoundCheckArray(int len) : arrlen(len)
{
	arr = new W[len];
}
template <class W>
W& BoundCheckArray<W>::operator[] (int idx)
{
	return arr[idx];
}
template <class W>
W BoundCheckArray<W>::operator[] (int idx) const
{
	return arr[idx];
}
template <class W>
int BoundCheckArray<W>::GetArrLen() const
{
	return arrlen;
}
template <class W>
BoundCheckArray<W>::~BoundCheckArray()
{
	delete[]arr;
}
#endif
