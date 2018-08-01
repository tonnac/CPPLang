#include <iostream>
using namespace std;

int main()
{
	int num = 0x010203;
	char * ptr = reinterpret_cast<char*>(&num);

	for (int i = 0; i < sizeof(num);i++)
	{
		cout << static_cast<int>(*(ptr + i)) << endl;
	}

	int num1 = 72;
	int * ptr1 = &num1;

	size_t addr = reinterpret_cast<size_t>(&num1);
//	__int64 addd = reinterpret_cast<int*>(ptr1);
	
	int * ptr3 = (int*)addr;

	cout << (int*)addr << endl;
//	cout << (int*)addd << endl;

	return 0;
}