#include "List.cpp"
#include <list>
int main()
{
	List<int> pl;
	pl.push_front(3);
	pl.push_back(4);
	pl.push_front(5);
	pl.push_front(6);
	pl.push_front(7);
	pl.push_back(8);

	List<int>::iterator iter = pl.begin();
	iter++;
	iter++;
	for (;iter != pl.begin();iter--)
	{
		std::cout << iter->getData() << std::endl;
	}

	std::list<int*> eee;
	int * ptr = new int(3);

	return 0;
}