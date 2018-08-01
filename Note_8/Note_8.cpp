#include "StringClass.h"
#include <iostream>
#include <cctype>

using namespace std;

class Exception
{
private:
public:
	virtual void ShowException(void) const = 0;
};

template<class K>
class Exceptioninherit : public Exception
{
private:
	K ex;
public:
	Exceptioninherit(const K& src) : ex(src)
	{}
	void ShowException(void) const
	{
		cout << (K)ex << "은 입력할수 없습니다." << endl;
	}
};

int main()
{
	int a;
	cin >> a;
	if (isdigit(a))
	{
		cout << "오!" << endl;
	}
	//while (true)
	//{
	//	try
	//	{
	//		cin >> a;
	//		if (a == 'a')
	//		{
	//			throw Exceptioninherit<char>(a);
	//		}
	//		break;
	//	}
	//	catch (const Exception& ab)
	//	{
	//		ab.ShowException();

	//	}
	//}
	return 0;
}