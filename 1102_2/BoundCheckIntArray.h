#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend ostream& operator<<(ostream& os, const Point* pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}
ostream& operator<<(ostream& os, const Point* pos)
{
	os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
	return os;
}

template <class T,typename T2>
class BoundCheck2DIntArray
{
private:
	T * arr;
	int m_iRow;
	int m_iColumn;
	int m_iValue;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& data) {}
	BoundCheck2DIntArray& operator =(const BoundCheck2DIntArray& data) {}
public:
	BoundCheck2DIntArray<T,T2>(int row,int column) : m_iRow(row), m_iColumn(column)
	{
		arr = new T[row];
		for (int i = 0; i < row; i++)
		{
			arr[i] = new T2[column];
		}
	}
	T* operator[] (int idx)
	{
		return *(arr+idx);
	}
	T& operator[] (int idx)
	{
		return arr[idx];
	}

	//T& operator[] (int row, int column)
	//{
	//	return (arr[column])[row];
	//}

	int GetArrRow() const { return m_iRow; }
	int GetArrCol() const { return m_iColumn; }
	~BoundCheck2DIntArray()
	{	
		for (int i = 0; i < m_iRow; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
};
