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
	Person(const char * myname, int myage) : age(myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
	}
	Person(const Person & data) : age(data.age)
	{
		int len = strlen(data.name) + 1;
		name = new char[len];
		strcpy(name, data.name);
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main()
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
}