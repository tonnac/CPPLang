#include <iostream>

using namespace std;

using IPL = size_t;


int main(void)
{
	IPL num = 10;
	IPL i = 0;

	cout << "true: " << true << endl;
	cout << "false: " << false << endl;

	while (true)
	{
		cout << i++ << ' ';
		if (i > num)
		{
			break;
		}
	}
	cout << endl;

	cout << "sizeof 1: " << sizeof(1) << endl;
	cout << "sizeof 0: " << sizeof(0) << endl;
	cout << "sizeof true: " << sizeof(true) << endl;
	cout << "sizeof false: " << sizeof(false) << endl;


	return 0;
}