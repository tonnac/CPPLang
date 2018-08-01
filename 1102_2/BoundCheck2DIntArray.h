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


class BoundCheckIntArray
{
private:
	int * ptr;
	BoundCheckIntArray(int num)
	{
		ptr = new int[num];
	}
public:
	int& operator[](int idx)
	{
		return ptr[idx];
	}
	friend class BoundCheck2DIntArray;
};




class BoundCheck2DIntArray
{
private:
	BoundCheckIntArray ** arr;
	int m_iRow;
	int m_iColumn;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& data) {}
	BoundCheck2DIntArray& operator =(const BoundCheck2DIntArray& data) {}
public:
	BoundCheck2DIntArray(int row,int column) : m_iRow(row), m_iColumn(column)
	{
		arr = new BoundCheckIntArray*[row];
		for (int i = 0; i < row; i++)
		{
			arr[i] = new BoundCheckIntArray(column);
		}
	}
	BoundCheckIntArray& operator[] (const int& idx)
	{
		return **(arr+idx);
	}
	//T& operator[] (int idx) const
	//{
	//	return arr[idx];
	//}

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
