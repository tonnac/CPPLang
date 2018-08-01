#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
	char * name;
	int age;
public:
	Person(const char * myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}

	~Person()
	{
		delete[]name;
		cout << "called desturctor!" << endl;
	}
};

int main()
{
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
}