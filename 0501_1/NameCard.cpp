#define _CRT_SECURE_NO_WARNINGS
#include "NameCard.h"

NameCard::NameCard(const char *_name, const char * _companyname, const char * _phonenum,int _rank)
	: Rank(_rank)
{
	Name = new char[(strlen(_name) + 1)];
	strcpy(Name, _name);
	CompanyName = new char[(strlen(_companyname) + 1)];
	strcpy(CompanyName, _companyname);
	PhoneNum = new char[(strlen(_phonenum) + 1)];
	strcpy(PhoneNum, _phonenum);
}
NameCard::NameCard()
{
}
NameCard::NameCard(const NameCard & data) : Rank(data.Rank)
{
	Name = new char[(strlen(data.Name) + 1)];
	strcpy(Name, data.Name);
	CompanyName = new char[(strlen(data.CompanyName) + 1)];
	strcpy(CompanyName, data.CompanyName);
	PhoneNum = new char[(strlen(data.PhoneNum) + 1)];
	strcpy(PhoneNum, data.PhoneNum);
}

NameCard::~NameCard()
{
	delete[]Name;
	Name = NULL;
	delete[]CompanyName;
	CompanyName = NULL;
	delete[]PhoneNum;
	PhoneNum = NULL;
}

void NameCard::ShowNameCardInfo()
{
	char * rank = new char[10];
	cout << "이름: " << Name << endl;
	cout << "회사: " << CompanyName << endl;
	cout << "전화번호: " << PhoneNum << endl;
	cout << "직급: "; COMP_POS::ShowPosInfo(Rank); 
}