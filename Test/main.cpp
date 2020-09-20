#include <cmath>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main()
{
	auto n = high_resolution_clock::now();

	__int64 p = pow(2, 32);

	for (__int64 i = 0; i < p; ++i)
	{

	}

	auto d = high_resolution_clock::now();


	duration<double> s = d - n;


	return 0;
}