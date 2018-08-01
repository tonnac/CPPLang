#include "Car1.h"


void Car::InitMembers(const char * ID, int fuel)
{
	strcpy_s(gameID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

void Car::ShowCarState()
{
	cout << "소유자ID:" << gameID << endl;
	cout << "연료량:" << fuelGauge << "%" << endl;
	cout << "현재속도:" << curSpeed << "km/s" << endl << endl;
}
