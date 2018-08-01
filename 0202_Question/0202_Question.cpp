#include <iostream>
using namespace std;

int main()
{
	const int num = 12;
	const int * ptr = &num;
	const int *& pref = ptr;

	cout << "num: " << num << endl;
	cout << "*ptr: " << *ptr << endl;
	cout << "*&pref: " << *pref << endl;

	return 0;
}