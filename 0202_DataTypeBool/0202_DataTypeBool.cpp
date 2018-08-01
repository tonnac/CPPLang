#include <iostream>

using namespace std;

using BO = bool;


BO IsPositive(int num)
{
	if (num <= 0)
		return false;
	else
		return true;
}


int main()
{
	BO isPos;
	int num;
	cout << "Input Number: ";
	cin >> num;

	isPos = IsPositive(num);
	if (isPos)
		cout << "Positive number" << endl;
	else
		cout << "Negative number" << endl;



	return 0;
}