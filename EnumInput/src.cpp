#include <iostream>
#include <fstream>
#include <string>
#include <tchar.h>

namespace std
{
	using tstring = std::basic_string<TCHAR>;
	using tistringstream = std::basic_istringstream<TCHAR>;
	using tostringstream = std::basic_ostringstream<TCHAR>;
	using tstringstream = std::basic_stringstream<TCHAR>;

	using tofstream = std::basic_ofstream<TCHAR>;
	using tifstream = std::basic_ifstream<TCHAR>;
	using tfstream = std::basic_fstream<TCHAR>;
}
using namespace std;

enum pe
{
	PEEP,
	EKE
};

tfstream& operator >> (tfstream& fp, pe& type)
{
	int k;
	fp >> k;
	type = (pe)k;
	return fp;
}

int main()
{
	float ep;
	tfstream fp("qq.txt", ios::out | ios::in);
	pe type;
	pe type1;
	if (fp.is_open() == false)
	{
		return 0;
	}

	fp >> ep >> type >> type1;
	fp >> type1;
	fp >> ep;
	return 0;
}