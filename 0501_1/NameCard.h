#pragma once
#include <iostream>
#include <cstring>

using namespace std;

#ifndef COMP_POS
#define COMP_POS
namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPosInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "���" << endl << endl;
			break;
		case SENIOR:
			cout << "����" << endl << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl << endl;
			break;
		case MANAGER:
			cout << "����" << endl << endl;
		}
	}
}
#endif

class NameCard
{

public:
	NameCard(const char *_name, const char * _companyname, const char * _phonenum, int _rank);
	void ShowNameCardInfo();
	NameCard(const NameCard & data);
	~NameCard();
	NameCard();
private:
	char * Name;
	char * CompanyName;
	char * PhoneNum;
	int Rank;
};