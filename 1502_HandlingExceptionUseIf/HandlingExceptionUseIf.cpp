#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "�� ���� ���� �Է�: ";
	cin >> num1 >> num2;

	if (num2 == 0)
	{
		cout << "������ 0�� �� �� �����ϴ�." << endl;
	}
	else
	{
		cout << "�������� ��: " << num1 / num2 << endl;
		cout << "�������� ������: " << num1 % num2 << endl;
	}
	return 0;
}