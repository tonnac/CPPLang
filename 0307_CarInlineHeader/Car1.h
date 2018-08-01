#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}


class Car
{
private:
	char gameID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

public:

	void ShowCarState()
	{
		cout << "소유자ID:" << gameID << endl;
		cout << "연료량:" << fuelGauge << "%" << endl;
		cout << "현재속도:" << curSpeed << "km/s" << endl << endl;
	}
	void Accel();
	void Break();
	void InitMembers(const char * ID, int fuel);

};
