#include <iostream>
#include <cstring>

using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum=0) : bullet(bnum)
	{}
	int GetBullet() const { return bullet; }
	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun * pistol;
public:
	Police(int bnum=0, int bcuff=0)
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(const Police& ref)
	{
		pistol = new Gun(ref.pistol->GetBullet());
		handcuffs = ref.handcuffs;
	}
	Police& operator = (const Police& ref)
	{
		if (pistol)
		{
			delete pistol;
			if (ref.pistol)
			{
				pistol = new Gun(ref.pistol->GetBullet());
			}
			else
			{
				pistol = NULL;
			}
		}
		else
		{
			pistol = NULL;
		}
		handcuffs = ref.handcuffs;
		return *this;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs++;
	}
	void Shot()
	{
		if (pistol == NULL)
			cout << "Hut BBANG" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main()
{
	Police pman(5, 3);
	pman.Shot();
	pman.PutHandcuff();

	Police pman1 = pman;
	pman1.Shot();

	Police pman2(0, 3);
	Police pman3;
	pman1 = pman2;
	pman3 = pman2;
	pman3.Shot();
	pman3.PutHandcuff();
}