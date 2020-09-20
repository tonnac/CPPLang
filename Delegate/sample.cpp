#include "delegate.h"

void PPP()
{
	std::cout << "PPP" << std::endl;
}

void QQQ()
{
	std::cout << "QQQ" << std::endl;
}

int main()
{
	Delegate D;

	D.AddFunc(&PPP);
	D.AddFunc(&QQQ);

	D.BroadCast();

	auto d = &QQQ;

	D.RemoveFunc(&PPP);


	D.BroadCast();
	return 0;
}