#include <iostream>

using namespace std;


class SoSimple
{
private:
	static int simObjCnt;
public:
	static void showCnt()
	{
		cout << simObjCnt << endl;
	}
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "¹øÂ° SoSimple °´Ã¼" << endl;
	}
};
int SoSimple::simObjCnt = 0;

class SoComplex
{
public:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "¹øÂ° SoComplex °´Ã¼" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "¹øÂ° SoComplex °´Ã¼" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main()
{
	SoSimple::showCnt();
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();
}