#include <iostream>
#include <cstring>

using namespace std;

class Computer
{
private:
	char owner[50];
public:
	Computer(const char * name)
	{
		strcpy_s(owner, 50, name);
	}
	void Calculate()
	{
		cout << "��û ������ ���." << endl;
	}
};

class NotebookComp : public Computer
{
private :
	int Battery;
public:
	NotebookComp(const char * name, int initChan)
		:Computer(name), Battery(initChan)
	{}
	void Charging() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp
{
private:
	char regstPenModel[50];
public:
	TabletNotebook(const char * name, int initChag, const char * pen)
		: NotebookComp(name, initChag)
	{
		strcpy_s(regstPenModel, 50, pen);
	}
	void Write(const char * penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo))
		{
			cout << "��ϵ� ���� �ƴմϴ�." << endl;
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
};

int main()
{
	NotebookComp nc("�̼���", 0);
	TabletNotebook tn("������", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
}