#include <iostream>
#include <tuple>

using namespace std;

void print()
{

}

template<typename A, typename...ARGS>
void print(A a, ARGS...args)
{
	cout << a << endl;
	print(args...);
}

int main()
{
	print(1, 2, 3, 4, 5, "ee", "fff");

	return 0;
}