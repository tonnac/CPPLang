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
	T& operator[] (int idx) const
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
	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

template <class T>
void ShowAllData(const BoundCheckIntArray<T>& ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
	{
		cout << ref[idx] << endl;
	}
}

int main()
{
	BoundCheckIntArray<double>drr(5);
	for (int i = 0;i < 5;i++)
	{
		drr[i] = static_cast<double>((i + 1) * 11);
	}
	ShowAllData(drr);
	return 0;
}