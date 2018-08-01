#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Girl;

class Boy
{
private:
	int height;
	friend class Girl;
public:
	Boy(int len) : height(len)
	{}
	void ShowYourFriendInfo(const Girl & frn) const;
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char * num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFrinedInfo(const Boy &frn) const;
	friend class Boy;
};

void Boy::ShowYourFriendInfo(const Girl & frn) const
{
	cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFrinedInfo(const Boy &frn) const
{
	cout << "His height: " << frn.height << endl;
}

int main()
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFrinedInfo(boy);
}