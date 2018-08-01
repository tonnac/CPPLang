#include "AccountHandler.h"


void MainMenu::title()
{
	while (true)
	{
		cout << "---------Menu---------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입  금" << endl;
		cout << "3. 출  금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 랜듐 생성" << endl;
		cout << "6. 프로그램 종료" << endl;
		int iSelect;
		cout << "선택: ";
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
			cout << "잘못된 입력입니다." << endl << endl;
		}
	}
}
void MainMenu::Account_Type()
{
	int iSelectinterest;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
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

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> _Account_num;
	cout << "이  름: ";	cin >> name;
	while(true)
	{
		try 
		{
			cout << "입금액: ";	cin >> _Deposit_num;
			if (_Deposit_num < 0)
				throw DepositException(_Deposit_num);
			break;
		}
		catch(const AccountException& expn)
		{
			expn.ShowException();
		}
	}
	cout << "이자율: "; cin >> interest;
	if (_Deposit_num < 0)
	{
		system("cls");
		cout << "잘못된 입력입니다." << endl << endl;
		return;
	}
	arr.AddArray(new NormalAccount(name, _Account_num, _Deposit_num, interest));
	system("cls");
	cout << "계좌 생성 완료!" << endl << endl;
}
void MainMenu::HighCredit_Account_create()
{
	int _Account_num;
	STRING name;
	int _Deposit_num;;
	int interest;
	int Highcredit;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> _Account_num;
	cout << "이  름: ";	cin >> name;
	while (true)
	{
		try
		{
			cout << "입금액: ";	cin >> _Deposit_num;
			if (_Deposit_num < 0)
				throw DepositException(_Deposit_num);
			break;
		}
		catch (const AccountException& expn)
		{
			expn.ShowException();
		}
	}
	cout << "이자율: "; cin >> interest;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> Highcredit;
	if (_Deposit_num < 0)
	{
		system("cls");
		cout << "잘못된 입력입니다." << endl << endl;
		return;
	}
	if (Highcredit == 1)		arr.AddArray(new HighCreditAccount(name, _Account_num, _Deposit_num, interest, HighCredit::A));
	else if (Highcredit == 2)	arr.AddArray(new HighCreditAccount(name, _Account_num, _Deposit_num, interest, HighCredit::B));
	else						arr.AddArray(new HighCreditAccount(name, _Account_num, _Deposit_num, interest, HighCredit::C));
	system("cls");
	cout << "계좌 생성 완료!" << endl << endl;
}
void MainMenu::Deposit() const
{
	int AccNum;
	int Money;
	Account * Src = NULL;
	cout << "[입	금]" << endl;
	cout << "계좌ID: ";cin >> AccNum;
	while (true)
	{
		try
		{
			cout << "입금액: ";	cin >> Money;
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
		cout << "입금완료" << endl << endl;
	}
	else
	{
		system("cls");
		cout << "잘못된 입력입니다." << endl << endl;
	}
}
void MainMenu::Withdraw() const
{
	int AccNum;
	int Money;
	Account * Src = NULL;

	cout << "[출	금]" << endl;
	cout << "계좌ID: ";	cin >> AccNum;
	Src = SearchAcc(AccNum);
	while (true)
	{
		try
		{
			cout << "출금액: ";	cin >> Money;
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
		cout << "출금완료" << endl << endl;
	}
	else
	{
		system("cls");
		cout << "잘못된 입력입니다." << endl << endl;
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
	cout << "해당하는 번호의 계좌가 존재하지 않습니다." << endl << endl;
	return NULL;
}
void MainMenu::Print_All() const
{
	system("cls");
	Account * Print = arr.GetpHead();
	cout << "[계좌정보]" << endl;
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