#include <iostream>
#include "StringClass.h"

using namespace std;

template <typename K>
class Point
{
private:
	K xpos, ypos;
public:
	Point(K x = 0, K y = 0);
	void ShowPosition() const;
};
template <typename K>
Point<K>::Point(K x, K y) : xpos(x), ypos(y)
{}
template <typename K>
void Point<K>::ShowPosition() const
{
	cout << xpos << ", " << ypos << endl;
}

template <typename K>
class SimpleDataWrapper
{
private:
	K mdata;
public:
	SimpleDataWrapper(K data) : mdata(data)
	{
		cout << "<K>" << endl;
	}
	void ShowDataInfo(void)
	{
		cout << "Data: " << mdata << endl;
	}
};

template<>
class SimpleDataWrapper <STRING>
{
private:
	STRING mdata;
public:
	SimpleDataWrapper(const STRING& data) : mdata(data)
	{
		cout << "<STRING>" << endl;
	}
	void ShowDataInfo(void)
	{
		cout << "String: " << mdata;
		cout << "Length: " << mdata.GetLen() << endl;
	}
};

template<>
class SimpleDataWrapper <Point<int>>
{
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) : mdata(x,y)
	{
		cout << "<Point<int>>" << endl;
	}
	void ShowDataInfo(void)
	{
		mdata.ShowPosition();
	}
};

int main()
{
	SimpleDataWrapper<int> iwrap(170);
	iwrap.ShowDataInfo();
	SimpleDataWrapper<STRING> swarp("Class Template Specialization");
	swarp.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap(3, 7);
	poswrap.ShowDataInfo();
	return 0;
}