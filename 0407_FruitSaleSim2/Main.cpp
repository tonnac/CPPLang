#include "FruitBuyer.h"
#include "FruitSeller.h"

int main()
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(13578);
	buyer.BuyAppels(seller, 5462);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
}