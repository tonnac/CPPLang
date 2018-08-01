#include "SalesWorker.h"

namespace RISK_LEVEL
{
	enum{RISK_C = 10, RISK_B = 20, RISK_A = 30};
}

class ForeignSalesWorker : public SalesWorker
{
public:
	ForeignSalesWorker(const char * _name, int _money, double ratio, int m)
		: SalesWorker(_name, _money, ratio), riskpay(m)
	{}
	int GetRiskPay() const
	{
		return (SalesWorker::GetPay())*((double)riskpay / 100);
	}
	int GetPay() const
	{
		return (SalesWorker::GetPay())*(1 + (double)riskpay / 100);
	}
	void ShowSalaryInfo() const
	{
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}
private:
	const int riskpay;
};