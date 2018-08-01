#include <iostream>
#include <conio.h>

namespace mystd
{
	class istream
	{
	public:
		istream& operator >> (char * str)
		{
			scanf_s("%s", str);
			return *this;
		}
		istream& operator >> (char& str)
		{
			scanf_s("%c", &str);
			return *this;
		}
		istream& operator >> (double& rad)
		{
			scanf_s("%lf", &rad);
			return *this;
		}
		istream& operator >> (int& num)
		{
			scanf_s("%d", &num);
			return *this;
		}
	};

	istream cin;
}

int main()
{
	using mystd::cin;
	int a;
	cin >> a;
	_getch();
}