#include <iostream>

using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car() : gasolineGauge(10)
	{
		cout << "Car Cons" << endl;
	}
	Car(int n) : gasolineGauge(n)
	{}
	~Car()
	{
		cout << "Car" << endl;
	}
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int eletricGauge;
public:
	HybridCar() : eletricGauge(20)
	{
		cout << "Hybrid Cons" << endl;
	}
	HybridCar(int n) : eletricGauge(n)
	{}
	HybridCar(int gas, int elec) : Car(gas), eletricGauge(elec)
	{}
	~HybridCar()
	{
		cout << "Hybrid Car" << endl;
	}
	int GetElecgauge()
	{
		return eletricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar() : waterGauge(30)
	{
		cout << "HybirdWater cons" << endl;
	}
	HybridWaterCar(int n) : waterGauge(n)
	{}
	HybridWaterCar(int n, int m) : waterGauge(n), HybridCar(m)
	{}
	HybridWaterCar(int n, int m, int k) : waterGauge(n), HybridCar(m,k) 
	{}
	~HybridWaterCar()
	{
		cout << "HybridWatercar" << endl;
	}
	void ShowCurrentGauge()
	{
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecgauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGauge << endl << endl;
	}
};

int main()
{
	HybridWaterCar h1;
	//HybridWaterCar h2(25);
	//HybridWaterCar h3(12, 32);
	//HybridWaterCar h4(99, 50, 75);

	h1.ShowCurrentGauge();
	//h2.ShowCurrentGauge();
	//h3.ShowCurrentGauge();
	//h4.ShowCurrentGauge();
}