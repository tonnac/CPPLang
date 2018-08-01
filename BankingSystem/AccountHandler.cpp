#include "AccountHandler.h"


void MainMenu::title()
{
	while (true)
	{
		cout << "---------Menu---------" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. ��  ��" << endl;
		cout << "3. ��  ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���� ����" << endl;
		cout << "6. ���α׷� ����" << endl;
		int iSelect;
		cout << "����: ";
		cin >> iSelect;
		switch (iSelect)
		{
		case Menu::ACCOUNT_TYPE:
			Account_Type();
			break;
		case Menu::DEPOSIT:
			Deposit();
			break;
		case Menu::WITHDRAW:
			Withdraw();
			break;
		case Menu::PRINT_ALL_ACCOUNT:
			Print_All();
			break;
		case Menu::RANDOM_CREATE:
			RandomCreate();
			break;
		case Menu::EXIT:
			return;
		default:
			system("cls");
			cout << "�߸��� �Է��Դϴ�." << endl << endl;
		}
	}
}
void MainMenu::Account_Type()
{
	int iSelectinterest;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> iSelectinterest;
	if (iSelectinterest == Accounttype::NORMAL)
	{
		Normal_Account_create();
	}
	else
	{
		HighCredit_Account_create();
	}
}
void MainMenu::Normal_Account_create()
{
	int _Account_num;
	STRING name;
	int _Deposit_num;;
	int interest;

	cout << "[���°���]" << endl;
	cout << "����ID: ";	cin >> _Account_num;
	cout << "��  ��: ";	cin >> name;
	while(true)
	{
		try 
		{
			cout << "�Աݾ�: ";	cin >> _Deposit_num;
			if (_Deposit_num < 0)
				throw DepositException(_Deposit_num);
			break;
		}
		catch(const AccountException& expn)
		{
			expn.ShowException();
		}
	}
	cout << "������: "; cin >> interest;
	if (_Deposit_num < 0)
	{
		system("cls");
		cout << "�߸��� �Է��Դϴ�." << endl << endl;
		return;
	}
	arr.AddArray(new NormalAccount(name, _Account_num, _Deposit_num, interest));
	system("cls");
	cout << "���� ���� �Ϸ�!" << endl << endl;
}
void MainMenu::HighCredit_Account_create()
{
	int _Account_num;
	STRING name;
	int _Deposit_num;;
	int interest;
	int Highcredit;

	cout << "[���°���]" << endl;
	cout << "����ID: ";	cin >> _Account_num;
	cout << "��  ��: ";	cin >> name;
	while (true)
	{
		try
		{
			cout << "�Աݾ�: ";	cin >> _Deposit_num;
			if (_Deposit_num < 0)
				throw DepositException(_Deposit_num);
			break;
		}
		catch (const AccountException& expn)
		{
			expn.ShowException();
		}
	}
	cout << "������: "; cin >> interest;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> Highcredit;
	if (_Deposit_num < 0)
	{
		system("cls");
		cout << "�߸��� �Է��Դϴ�." << endl << endl;
		return;
	}
	if (Highcredit == 1)		arr.AddArray(new HighCreditAccount(name, _Account_num, _Deposit_num, interest, HighCredit::A));
	else if (Highcredit == 2)	arr.AddArray(new HighCreditAccount(name, _Account_num, _Deposit_num, interest, HighCredit::B));
	else						arr.AddArray(new HighCreditAccount(name, _Account_num, _Deposit_num, interest, HighCredit::C));
	system("cls");
	cout << "���� ���� �Ϸ�!" << endl << endl;
}
void MainMenu::Deposit() const
{
	int AccNum;
	int Money;
	Account * Src = NULL;
	cout << "[��	��]" << endl;
	cout << "����ID: ";cin >> AccNum;
	while (true)
	{
		try
		{
			cout << "�Աݾ�: ";	cin >> Money;
			if (Money <= 0)
				throw DepositException(Money);
			break;
		}
		catch (const AccountException& expn)
		{
			expn.ShowException();
		}
	}
	Src = SearchAcc(AccNum);
	if (Src->Deposit(Money))
	{
		system("cls");
		cout << "�ԱݿϷ�" << endl << endl;
	}
	else
	{
		system("cls");
		cout << "�߸��� �Է��Դϴ�." << endl << endl;
	}
}
void MainMenu::Withdraw() const
{
	int AccNum;
	int Money;
	Account * Src = NULL;

	cout << "[��	��]" << endl;
	cout << "����ID: ";	cin >> AccNum;
	Src = SearchAcc(AccNum);
	while (true)
	{
		try
		{
			cout << "��ݾ�: ";	cin >> Money;
			if (Src->GetDeposit() < Money)
				throw WithDrawException(Money);
			else if (Money <= 0)
				throw DepositException(Money);
			break;
		}
		catch (const AccountException& expn)
		{
			expn.ShowException();
		}
	}
	if (Src->WithDraw(Money))
	{
		system("cls");
		cout << "��ݿϷ�" << endl << endl;
	}
	else
	{
		system("cls");
		cout << "�߸��� �Է��Դϴ�." << endl << endl;
	}
}
Account* MainMenu::SearchAcc(const int &num) const
{
	Account * temp = arr.GetpHead();
	int AccNum;

	for (int i = 0; i < arr.GetCnt(); i++)
	{
		AccNum = temp->GetAccNum();
		if (num == AccNum)
		{
			return temp;
		}
		temp = temp->GetpNext();
	}
	system("cls");
	cout << "�ش��ϴ� ��ȣ�� ���°� �������� �ʽ��ϴ�." << endl << endl;
	return NULL;
}
void MainMenu::Print_All() const
{
	system("cls");
	Account * Print = arr.GetpHead();
	cout << "[��������]" << endl;
	for (int i = 0; i < arr.GetCnt();i++)
	{
		Print->DataShow();
		Print = Print->GetpNext();
		cout << endl;
	}
	cout << "========================" << endl;
}

void MainMenu::RandomCreate()
{
	int iSelect;
	char name[4];
	int _Account_num;
	int _Deposit_num;
	int interest;
	for (int i = 0; i < 20; i++)
	{
		name[0] = 65 + rand() % 26;
		name[1] = 65 + rand() % 26;
		name[2] = 65 + rand() % 26;
		name[3] = 0;
		_Account_num = rand() % 200;
		_Deposit_num = rand() % 200 + 200;
		interest = rand() % 10 + 5;
		iSelect = rand() % 2;
		if (iSelect == 0)
		{
			arr.AddArray(new NormalAccount(name, _Account_num, _Deposit_num, interest));
		}
		else
		{
			arr.AddArray(new HighCreditAccount(name, _Account_num, _Deposit_num, interest, HighCredit::A));
		}
	}
}