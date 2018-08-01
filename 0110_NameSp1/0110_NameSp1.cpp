#include <iostream>

namespace BestComImpl
{
	void SImpleFunc(void)
	{
		std::cout << "BestCom::SimpleFunc()" << std::endl;
	}
}

namespace ProgComImpl
{
	void SImpleFunc(void)
	{
		std::cout << "ProgComImpl::SimpleFunc()" << std::endl;
	}
}

int main()
{
	BestComImpl::SImpleFunc();
	ProgComImpl::SImpleFunc();

	return 0;
}