#include "FruitBuyer.h"
#include "FruitSeller.h"

int main()
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(13578);
	buyer.BuyAppels(seller, 5462);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
}