#include <iostream>

using namespace std;

class CountryArea
{
public:
	const static int RUSSIA = 1707540;
	const static int CANADA = 998467;
	const static int CHINA = 977290;
	const static int SOUTH_KOREA = 9922;
};

int main()
{
	cout << "�ξ��� ����: " << CountryArea::RUSSIA << "��" << endl;
	cout << "ĳ���� ����: " << CountryArea::CANADA << "��" << endl;
	cout << "�߱� ����: " << CountryArea::CHINA << "��" << endl;
	cout << "�ѱ� ����: " << CountryArea::SOUTH_KOREA << "��" << endl;
}