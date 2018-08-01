#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

class QUESTION_1
{
private:
	char * str;
public:
	void Showstr()
	{
		std::cout << str << std::endl;
	}
	void StrCat(const char * src)
	{
		char * pe = new char[strlen(str) + 1];
		strcpy(pe, str);
		delete[]str;
		str = new char[strlen(pe) + strlen(src) + 1];
		strcpy(str, pe);
		delete[]pe;
		strcat(str, src);
	}
	bool Cmp(const char * src)
	{
		if (!_stricmp(str, src))
			return true;
		return false;
	}
	QUESTION_1(const char * ch)
	{
		str = new char[strlen(ch) + 1];
		strcpy(str, ch);
	}
	~QUESTION_1()
	{
		delete[]str;
	}
};
class QUESTION_2
{
public:
	void Main()
	{
		srand((unsigned int)time(NULL));
		std::cout << rand() % 100 << std::endl;
		std::cout << rand() % 100 << std::endl;
		std::cout << rand() % 100 << std::endl;
		std::cout << rand() % 100 << std::endl;
		std::cout << rand() % 100 << std::endl;
	}
};

int main()
{
	QUESTION_1 p("QWE");
	p.Showstr();
	p.Cmp("qwe");
	p.Cmp("ee");
	p.StrCat("rrr");
	p.Showstr();

	QUESTION_2 l;
	l.Main();

	return 0;
}