#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "�� ���� ���� �Է�: ";
	cin >> num1 >> num2;

	try
	{
		if (num2 == 0)
			throw num2;
		cout << "�������� ��: " << num1 / num2 << endl;
		cout << "�������� ������: " << num1 % num2 << endl;
	}
	catch (int excp)
	{
		cout << excp << "�� ������ �� �� �����ϴ�." << endl;
	}
	return 0;
}