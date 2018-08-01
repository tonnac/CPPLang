#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base
{
private:
	int m_iValue;
public:
	//Base(const Base& T)
	//{
	//	std::cout << m_iValue << " Copy" << std::endl;
	//}

	Base(int n) : m_iValue(n)
	{
		std::cout << m_iValue << " Normal Cons" << std::endl;
	}

	Base() : m_iValue(0)
	{
		std::cout << "Default Cons" << std::endl;
	}

	//Base(Base&& src) noexcept
	//{
	//	std::cout << "Move Cons" << std::endl;
	//}

	//Base& operator=(Base && rhs) noexcept
	//{
	//	std::cout << "Move Assignment" << std::endl;
	//	return *this;
	//}
	Base& operator=(const Base & rhs)
	{
		std::cout << m_iValue << " Assignment" << std::endl;
		return *this;
	}

	friend const Base operator+ (const Base & lhs, const Base & rhs);

	~Base()
	{
		std::cout << m_iValue <<" Destructor" << std::endl;
	}
};

const Base operator+ (const Base & lhs, const Base & rhs)
{
	std::cout << lhs.m_iValue << " Operator+ " << rhs.m_iValue << std::endl;
	return Base(lhs.m_iValue+rhs.m_iValue);
}

void Show(Base Data)
{
	std::cout << &Data << std::endl;
}

Base CreateObj()
{
	return Base(5);
}

int main()
{
	Show(Base(5));
	//Base Data = Base(5);
	//Base p = Data;
	//Base c = Data;

	//vector<Base> Bas;
	//for (int i = 0; i < 2; i++)
	//{
	//	cout << "Iteration " << i << endl;
	//	Bas.push_back(Base(3));
	//	cout << endl;
	//}
	//
	//Base s(3);
	//s = CreateObj();
	//Base d(1);
	//d = s;

	//Base a(4), b;
	//b = a + 3;
	//b = a + 5;


	return 0;
}

