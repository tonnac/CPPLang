#include "EmployeeHandler.h"
#include "PermanentWorker.h"
#include "TemporaryWorker.h"
#include "SalesWorker.h"

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

	//�̹� �� ���ұ޿� ����
	handler.ShowAllSalaryInfo();

	//�̹� �� ���� �޿� ����
	handler.ShowTotalSalary();
}