#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
	char * name;
public:
	Person(const char * myname)
	{
		name = new char[strlen(myname) + 1];
		strcpy_s(name, strlen(myname) + 1,myname);
	}
	~Person()
	{
		cout << "Person " << name << " Destruct!" << endl;
		delete[]name;
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
};

class UnivStudent : public Person
{
private:
	char * major;
public:
	UnivStudent(const char * myname, const char * mymajor)
		: Person(myname)
	{
		major = new char[strlen(mymajor) + 1];
		strcpy_s(major, strlen(mymajor) + 1, mymajor);
	}
	~UnivStudent()
	{
		cout << "Univ " << major << " Destruct!" << endl;
		delete[]major;
	}
	void WhoAreYou() const
	{
		WhatYourName();
		cout << "My major is " << major << endl << endl;
	}
};

int main()
{
	UnivStudent st1("Kim", "Mathmatics");
	st1.WhoAreYou();
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();
}