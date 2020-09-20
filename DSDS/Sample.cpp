#include <iostream>
#include <map>

int EE(int number)
{
	int e = number;

	while (number > 0)
	{
		e += number % 10;
		number /= 10;
	}

	return e;
}

int main()
{
	//std::map<int, bool> asd;

	//int result = 0;

	//for (int i = 1; i < 5000; ++i)
	//{
	//	result += i;
	//	int e = EE(i);
	//	if (e < 5000)
	//	{
	//		asd.insert(std::make_pair(e, true));
	//	}
	//}

	//for (auto& d : asd)
	//{
	//	result -= d.first;
	//}

	unsigned char e = 1;
	int d = 257;

	if (unsigned char(d) == e)
	{
		std::cout << "ee" << std::endl;
	}
	return 0;
}