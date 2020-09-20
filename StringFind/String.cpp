#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string ep = "../../data/eee.png";

	string ll;
	ll.assign(ep,ep.find_last_of('/') + 1,ep.find_last_of('.'));

	return 0;
}