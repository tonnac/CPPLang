#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string ee = "../../momodora/data/ui/inventory/Flower.png";
	string ep;
	ep.assign(ee, 0, ee.find_last_of('.'));
	ep += "Desc.png";
	string qe;
	qe.assign(ee, 0, ee.find_last_of('.'));
	string eeq = ee + "Name";

	vector<int> aaa;
	aaa.resize(2);
	aaa[0] = 3;
	aaa[1] = 4;

	auto foo = [](const int& ee, const int& qq)
	{
		if (ee < qq)
		{
			return true;
		}
		return false;
	};

	aaa.push_back(1);
	sort(aaa.begin(), aaa.end(), foo);

    return 0;
}

