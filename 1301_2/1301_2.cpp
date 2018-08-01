#include <iostream>
#include <ctime>

using namespace std;

template <class DD>
DD SumArray(DD arr[], int len)
{
	DD Sum = 0;
	for (int i = 0; i < len; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}

int main()
{
	srand(time(NULL));
	int arr[5];
	double brr[5];
	short crr[5];
	char drr[5];

	brr[0] = 1.2;
	brr[1] = 3.14;
	brr[2] = 6.454;
	brr[3] = 9.123;
	brr[4] = 4.5234;

	for (int i = 0; i < 5; i++)
	{
		arr[i] = rand() % 10;
		crr[i] = rand() % 10;
		drr[i] = 13;
	}

	cout << SumArray(arr, sizeof(arr) / sizeof(int)) << endl;
	cout << SumArray(brr, sizeof(brr) / sizeof(double)) << endl;
	cout << SumArray(crr, sizeof(crr) / sizeof(short)) << endl;
	cout << SumArray(drr, sizeof(drr) / sizeof(char)) << endl;
	

}