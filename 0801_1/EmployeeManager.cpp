#include "EmployeeHandler.h"
#include "PermanentWorker.h"
#include "TemporaryWorker.h"
#include "SalesWorker.h"
#include "ForeignSalesWorker.h"

int main()
{
	EmployeeHandler handler;

	//정규직 등록
	//handler.AddEmployee(new PermanentWorker("KIM", 1000));
	//handler.AddEmployee(new PermanentWorker("LEE", 1500));
	//handler.AddEmployee(new PermanentWorker("JUN", 2000));

	////임시직 등록
	//TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	//alba->AddWorkTime(5);
	//handler.AddEmployee(alba);

	////영업직 등록
	//SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	//seller->AddSalesResult(7000);
	//handler.AddEmployee(seller);

	//해외영업직 등록
	ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker * fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker * fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	//이번 달 지불급여 정보
	handler.ShowAllSalaryInfo();

	//이번 달 지불 급여 총합
//	handler.ShowTotalSalary();
}