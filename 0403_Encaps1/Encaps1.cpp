#include <iostream>
using namespace std;

class SinvelCap
{
public:
	void Take() const { cout << "Äà¹°ÀÌ ½Ï~ ³³´Ï´Ù." << endl; }
};

class SneezeCap
{
public:
	void Take() const { cout << "ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù." << endl; }
};

class SnuffleCap
{
public:
	void Take() const { cout << "ÄÚ°¡ »½ ¶Õ¸³´Ï´Ù." << endl; }
};

class ColdPatient
{
public:
	void TakeSinvelCap(const SinvelCap & cap) const { cap.Take(); }
	void TakeSneezeCap(const SneezeCap & cap) const { cap.Take(); }
	void TakeSnuffleCap(const SnuffleCap & cap) const { cap.Take(); }
};

int main(void)
{
	SnuffleCap ncap;
	SneezeCap zcap;
	SinvelCap scap;

	ColdPatient sufferer;
	sufferer.TakeSinvelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
}