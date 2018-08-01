#include "0101_Question.h"

void QUESTION_1::Main()
{
	input();
	std::cout << "합계: " << Sumarray() << std::endl;
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
		std::cout << i + 1 << "번째 정수 입력: ";
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
	std::cout << "이름입력: ";
	std::cin >> name;
	std::cout << "번호입력: ";
	std::cin >> Phone;
}
void QUESTION_2::output()
{
	std::cout << "이름: " << name << std::endl;
	std::cout << "번호: " << Phone << std::endl;
}

////////////////////////////////////////////////////////////////////

void QUESTION_3::Main()
{
	input();
	output();
}
void QUESTION_3::input()
{
	std::cout << "숫자입력: ";
	std::cin >> m_iValue;
}
void QUESTION_3::output()
{
	for (int i = 1; i < 10; i++)
	{
		std::cout << m_iValue << " × " << i << " = " << m_iValue * i << std::endl;
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
	std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
	std::cin >> m_iSales;
	if (m_iSales == -1)
	{
		std::cout << "프로그램을 종료합니다." << std::endl;
		return false;
	}
	return true;
}
void QUESTION_4::ShowPay()
{
	m_iBonus = m_iSales * 0.12;
	std::cout << "이번 달 급여: " << m_iPay + m_iBonus << std::endl;
}