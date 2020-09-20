#include "Floyd.h"

#define INF	10000

int main(void)
{
	int grapharr[4][4] = {
	{1,1,INF,INF },
	{1,1,INF,1 },
	{INF,INF,1,1},
	{INF,1,1,1}
	};
	ShowGraph(grapharr, 4); std::cout << std::endl;

	Floyd::CreateFloyd(grapharr);
	ShowGraph(grapharr, 4);

	return 0;
}