#include "StudentHandler.h"

std::istream& operator >> (std::istream&is, StudentHandler::MENU& type)
{
	int num;
	is >> num;
	type = static_cast<StudentHandler::MENU>(num);
	return is;
}
std::istream& operator >> (std::istream&is, StudentHandler::SELECT& type)
{
	int num;
	is >> num;
	type = static_cast<StudentHandler::SELECT>(num);
	return is;
}

void StudentHandler::MainMenu()
{
	while (1)
	{
		MENU type = MENU::ADD;
		std::cout << "[�л����� ���α׷�]" << std::endl;
		std::cout << "1.�л� �߰�" << std::endl;
		std::cout << "2.�л� �˻�" << std::endl;
		std::cout << "3.�л� ����" << std::endl;
		std::cout << "4.�л� ����" << std::endl;
		std::cout << "5.�л� ���" << std::endl;
		std::cout << "6.���� �Է�" << std::endl;
		std::cout << "7.���� ����" << std::endl;
		std::cout << "8.���� �ε�" << std::endl;
		std::cout << "9.���α׷� ����" << std::endl;
		std::cout << "�Է�: ";
		std::cin >> type;
		switch (type)
		{
		case MENU::ADD:
			AddData();
			break;
		case MENU::SEARCH:
			SearchData(0);
			break;
		case MENU::EDIT:
			EditData();
			break;
		case MENU::DELETE:
			DeleteData();
			break;
		case MENU::PRINT:
			PrintData();
			break;
		case MENU::RANDOM:
			RandomInput();
			break;
		case MENU::SAVE:
			SaveFile();
			break;
		case MENU::LOAD:
			LoadFile();
			break;
		case MENU::EXIT:
			std::cout << "���α׷��� �����մϴ�." << std::endl;
			return;
		default:
			system("cls");
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
	}
}
void StudentHandler::AddData()
{
	char cName[256];
	int iKor;
	int iMat;
	int iEng;
	std::cout << "�̸��Է�: ";
	std::cin >> cName;
	std::cout << "�������� �Է�: ";
	std::cin >> iKor;
	std::cout << "�������� �Է�: ";
	std::cin >> iMat;
	std::cout << "�������� �Է�: ";
	std::cin >> iEng;
	m_dStd.AddLink(new StudentData(cName, iKor, iMat, iEng));
	system("cls");
	std::cout << "�߰� �Ϸ�Ǿ����ϴ�." << std::endl;
}
void StudentHandler::SearchData(const int & DataType)
{
	while (1)
	{
		SELECT type = SELECT::NAME;
		std::cout << "�˻���� ����" << std::endl;
		std::cout << "1.�̸����� �˻�, 2.��ȣ�� �˻�" << std::endl;
		std::cout << "����: ";
		std::cin >> type;
		switch (type)
		{
		case SELECT::NAME:
			SearchName(DataType);
			return;
		case SELECT::NUMBER:
			SearchNumber(DataType);
			return;
		default:
			system("cls");
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
	}
}
void StudentHandler::EditData()
{
	SearchData(1);
}
void StudentHandler::DeleteData()
{
	SearchData(2);
}
void StudentHandler::PrintData()
{
	system("cls");
	m_dStd.PrintAllData();
}
void StudentHandler::RandomInput()
{
	char cName[256];
	int iKor;
	int iEng;
	int iMat;
	for (int i = 0; i < 40; i++)
	{
		cName[0] = rand() % 26 + 65;
		cName[1] = rand() % 26 + 65;
		cName[2] = rand() % 26 + 65;
		cName[3] = 0;
		iKor = rand() % 101;
		iMat = rand() % 101;
		iEng = rand() % 101;
		m_dStd.AddLink(new StudentData(cName, iKor, iMat, iEng));
	}
	system("cls");
	std::cout << "�Է��� �Ϸ�Ǿ����ϴ�." << std::endl;
}
void StudentHandler::SaveFile()
{
	m_fIO.FileSave(m_dStd);
}
void StudentHandler::LoadFile()
{
	char * szFile = NULL;

	szFile = m_fIO.Datafileload();
	if (szFile != NULL)
	{
		int Mode = m_fIO.Binarytextload(szFile);
		m_fIO.FileLoad(szFile, Mode,m_dStd);
	}
	else
	{
		system("cls");
		puts("���� �ҷ����� ����.");
	}
}

void StudentHandler::SearchName(const int & type)
{
	char cName[256];
	std::cout << "�̸��Է�: ";
	std::cin >> cName;
	StudentData * src = m_dStd.SearchByName(cName);
	if (src == nullptr)
	{
		system("cls");
		std::cout << "�ش��ϴ� �̸��� �������� �ʽ��ϴ�." << std::endl;
		return;
	}
	system("cls");
	src->OneShow();
	if (type == 1)
	{
		m_dStd.EditLink(src);
		return;
	}
	else if (type == 2)
	{
		char YN;
		std::cout << "������ �����Ͻðڽ��ϱ�?(Y/N): ";
		std::cin >> YN;
		if (YN == 'Y' || YN == 'y')
		{
			m_dStd.DelLink(src);
			system("cls");
			std::cout << "�����Ǿ����ϴ�." << std::endl;
			return;
		}
		else if (YN == 'N' || YN == 'n')
		{
			system("cls");
			std::cout << "��ҵǾ����ϴ�." << std::endl;
			return;
		}
		else
		{
			system("cls");
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			return;
		}
	}
}
void StudentHandler::SearchNumber(const int & type)
{
	int iNumber;
	std::cout << "��ȣ�Է�: ";
	std::cin >> iNumber;
	StudentData * src = m_dStd.SearchByNum(iNumber);
	if (src == nullptr)
	{
		system("cls");
		std::cout << "�ش��ϴ� ��ȣ�� �������� �ʽ��ϴ�." << std::endl;
		return;
	}
	system("cls");
	src->OneShow();
	if (type == 1)
	{
		m_dStd.EditLink(src);
		return;
	}
	else if (type == 2)
	{
		char YN;
		std::cout << "������ �����Ͻðڽ��ϱ�?(Y/N): ";
		std::cin >> YN;
		if (YN == 'Y' || YN == 'y')
		{
			m_dStd.DelLink(src);
			system("cls");
			std::cout << "�����Ǿ����ϴ�." << std::endl;
			return;
		}
		else if (YN == 'N' || YN == 'n')
		{
			system("cls");
			std::cout << "��ҵǾ����ϴ�." << std::endl;
			return;
		}
		else
		{
			system("cls");
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			return;
		}
	}
}