#include "EmployeeHandler.h"
#include "PermanentWorker.h"
#include "TemporaryWorker.h"
#include "SalesWorker.h"
#include "ForeignSalesWorker.h"

int main()
{
	EmployeeHandler handler;

	//������ ���
	//handler.AddEmployee(new PermanentWorker("KIM", 1000));
	//handler.AddEmployee(new PermanentWorker("LEE", 1500));
	//handler.AddEmployee(new PermanentWorker("JUN", 2000));

	////�ӽ��� ���
	//TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	//alba->AddWorkTime(5);
	//handler.AddEmployee(alba);

	////������ ���
	//SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	//seller->AddSalesResult(7000);
	//handler.AddEmployee(seller);

	//�ؿܿ����� ���
	ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker * fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker * fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	//�̹� �� ���ұ޿� ����
	handler.ShowAllSalaryInfo();

	//�̹� �� ���� �޿� ����
//	handler.ShowTotalSalary();
}