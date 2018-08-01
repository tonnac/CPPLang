#include <iostream>

namespace BestComImpl
{
	void SImpleFunc(void);
}

namespace ProgComImpl
{
	void SImpleFunc(void);
}

int main()
{
	BestComImpl::SImpleFunc();
	ProgComImpl::SImpleFunc();

	return 0;
}

void BestComImpl::SImpleFunc(void)
{
	std::cout << "BestCom::SimpleFunc()" << std::endl;
}

void ProgComImpl::SImpleFunc(void)
{
	std::cout << "ProgComImpl::SimpleFunc()" << std::endl;
}