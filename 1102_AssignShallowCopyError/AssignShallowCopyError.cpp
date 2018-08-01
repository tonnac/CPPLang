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
		strcpy_s(name,len ,myname);
		age = myage;
	}
	Person& operator = (const Person& data)
	{
		if (name)delete[]name;
		char * _name = new char[strlen(data.name) + 1];
		strcpy_s(_name, strlen(data.name) + 1, data.name);
		age = data.age;
		name = _name;
		return *this;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called Destructor!" << endl;
	}
};

int main()
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}