#include <iostream>

using namespace std;

class MyFriendInfo
{
private:
	char * name;
	int age;
public:
	MyFriendInfo(int _age) : age(_age)
	{
	}
	MyFriendInfo(const char * _name)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}
	MyFriendInfo(const char * _name, int _age) : age(_age)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}
	~MyFriendInfo()
	{
		delete[]name;
		cout << "Info Destruct Success" << endl;
	}
	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(const char * _name, int _age, const char * _addr, const char * _phone)
		: MyFriendInfo(_name, _age)
	{
		addr = new char[strlen(_addr) + 1];
		strcpy_s(addr, strlen(_addr) + 1, _addr);
		phone = new char[strlen(_phone) + 1];
		strcpy_s(phone, strlen(_phone) + 1, _phone);
	}
	~MyFriendDetailInfo()
	{
		delete[] addr;
		delete[] phone;
		cout << "Detail Destruct Success." << endl;
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
};

int main()
{
	MyFriendDetailInfo d1("ㅇㅇㅇ", 23, "서울", "010-1111-1111");
	d1.ShowMyFriendDetailInfo();
}