#include <iostream>

namespace BestComImpl
{
	void SImpleFunc(void);
}

namespace ProgComImpl
{
	void SImpleFunc(void);
}

namespace BestComImpl
{
	void PrettyFunc(void);
}


int main()
{
	BestComImpl::SImpleFunc();
	return 0;
}

void BestComImpl::SImpleFunc(void)
{
	PrettyFunc();
	ProgComImpl::SImpleFunc();
	std::cout << "BestCom::SimpleFunc()" << std::endl;
}

void ProgComImpl::SImpleFunc(void)
{
	std::cout << "ProgComImpl::SimpleFunc()" << std::endl;
}

void BestComImpl::PrettyFunc(void)
{
	std::cout << "So Pretty!!" << std::endl;
}