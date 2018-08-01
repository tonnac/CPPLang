#include "EmployeeHandler.h"
#include "PermanentWorker.h"
#include "TemporaryWorker.h"
#include "SalesWorker.h"

int main()
{
	EmployeeHandler handler;


	//정규직 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	//임시직 등록
	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	//영업직 등록
	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	//이번 달 지불급여 정보
	handler.ShowAllSalaryInfo();

	//이번 달 지불 급여 총합
	handler.ShowTotalSalary();
}