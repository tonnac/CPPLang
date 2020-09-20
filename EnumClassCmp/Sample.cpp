#include <iostream>

using namespace std;

enum class PE : char
{
	A = 0,
	B = 1,
	C = 2,
	D = 3
};

int main()
{
	if (PE::A < PE::B)
	{
		cout << "A<B" << endl;
	}

	if (PE::D > PE::A)
	{
		cout << "D>A" << endl;
	}


	return 0;
}