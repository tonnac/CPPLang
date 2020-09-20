#include "delegate.h"

void PPP()
{
	std::cout << "PPP" << std::endl;
}

void QQQ()
{
	std::cout << "QQQ" << std::endl;
}

#define EE(q,w) q w;

template<class T>
class AB
{
public:
	int e;
};

#define PP(a,b) AB<b> a;

int main()
{
	Delegate D;

	D.AddFunc(&PPP);
	D.AddFunc(&QQQ);

	D.BroadCast();

	auto d = &QQQ;

	D.RemoveFunc(&PPP);


	D.BroadCast();

	EE(float, e);
	PP(ab, int);
	ab.e;

	return 0;
}