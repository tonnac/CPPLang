#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class BoundCheckIntArray
{
private:
	T * arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& data) {}
	BoundCheckIntArray& operator =(const BoundCheckIntArray& data) {}
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new T[len];
	}
	T& operator[] (int idx)
	{
		try
		{
			if (idx < 0 || idx >= arrlen)
			{
				throw false;
			}
			return arr[idx];
		}
		catch (bool expn)
		{
			if (expn == false)
			{
				cout << "²¨Á®" << endl;
				exit(1);
			}
		}
	}
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

int main()
{
	BoundCheckIntArray<double>drr(5);
	for (int i = 0;i < 5;i++)
	{
		drr[i] = static_cast<double>((i + 1) * 11);
	}
	for (int i = 0;i < 6;i++)
	{
		cout << static_cast<double>(drr[i]) << endl;
	}
	return 0;
}