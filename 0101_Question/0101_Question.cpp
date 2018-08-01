#include "0101_Question.h"

void QUESTION_1::Main()
{
	input();
	std::cout << "�հ�: " << Sumarray() << std::endl;
}
int QUESTION_1::Sumarray()
{
	int result = 0;
	for (int i = 0; i < arrlen; i++)
	{
		result += arr[i];
	}
	return result;
}
void QUESTION_1::input()
{
	for (int i = 0; i < arrlen; i++)
	{
		std::cout << i + 1 << "��° ���� �Է�: ";
		std::cin >> arr[i];
	}
}
QUESTION_1::QUESTION_1(int len) : arrlen(len)
{
	arr = new int[arrlen];
}
QUESTION_1::~QUESTION_1()
{
	delete[]arr;
}

////////////////////////////////////////////////////////////////////

void QUESTION_2::Main()
{
	input();
	output();
}
void QUESTION_2::input()
{
	std::cout << "�̸��Է�: ";
	std::cin >> name;
	std::cout << "��ȣ�Է�: ";
	std::cin >> Phone;
}
void QUESTION_2::output()
{
	std::cout << "�̸�: " << name << std::endl;
	std::cout << "��ȣ: " << Phone << std::endl;
}

////////////////////////////////////////////////////////////////////

void QUESTION_3::Main()
{
	input();
	output();
}
void QUESTION_3::input()
{
	std::cout << "�����Է�: ";
	std::cin >> m_iValue;
}
void QUESTION_3::output()
{
	for (int i = 1; i < 10; i++)
	{
		std::cout << m_iValue << " �� " << i << " = " << m_iValue * i << std::endl;
	}
}

////////////////////////////////////////////////////////////////////

QUESTION_4::QUESTION_4() : m_iPay(50), m_iBonus(0), m_iSales(0)
{}
void QUESTION_4::Main()
{
	while (inputSales())
	{
		ShowPay();
	}
}
bool QUESTION_4::inputSales()
{
	std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
	std::cin >> m_iSales;
	if (m_iSales == -1)
	{
		std::cout << "���α׷��� �����մϴ�." << std::endl;
		return false;
	}
	return true;
}
void QUESTION_4::ShowPay()
{
	m_iBonus = m_iSales * 0.12;
	std::cout << "�̹� �� �޿�: " << m_iPay + m_iBonus << std::endl;
}