#include <iostream>
using namespace std;

template <typename T>
void ShowStaticValue(void)
{
	static T num = 0;
	num += 1;
	cout << num << " ";
}
template<char>
void ShowStaticValue(void)
{
	static char num = 0;
	num += 1;
	cout << static_cast<int>(num) << " ";
}

int main()
{
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	cout << endl;
	ShowStaticValue<short>();
	ShowStaticValue<short>();
	ShowStaticValue<short>();
	cout << endl;
	ShowStaticValue<char>();
	ShowStaticValue<char>();
	ShowStaticValue<char>();
	cout << endl;

	static char ch = 3;
	cout << ch << " " << static_cast<int>(ch) << endl;
	
	return 0;
}