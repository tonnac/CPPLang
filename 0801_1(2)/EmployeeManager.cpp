#include "EmployeeHandler.h"
#include "ForeignSalesWorker.h"
#include "TemporaryWorker.h"


int main()
{
	EmployeeHandler handler;


	//������ ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	//�ӽ��� ���
	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	//������ ���
	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	ForeignSalesWorker * fw = new ForeignSalesWorker("AAA", 1000, 0.1, RISK_LEVEL::RISK_A);
	ForeignSalesWorker * aa = new ForeignSalesWorker("BBB", 1000, 0.1, RISK_LEVEL::RISK_B);
	ForeignSalesWorker * ss = new ForeignSalesWorker("CCC", 1000, 0.1, RISK_LEVEL::RISK_C);
	fw->AddSalesResult(7000);
	aa->AddSalesResult(7000);
	ss->AddSalesResult(7000);
	handler.AddEmployee(fw);
	handler.AddEmployee(aa);
	handler.AddEmployee(ss);

	//�̹� �� ���ұ޿� ����
	handler.ShowAllSalaryInfo();

	//�̹� �� ���� �޿� ����
	handler.ShowTotalSalary();
}