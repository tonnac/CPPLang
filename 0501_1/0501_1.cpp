#include "NameCard.h"

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("HONG", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	NameCard Copy = manClerk;
	NameCard Copy1 = manSENIOR;
	NameCard Copy2 = manAssist;
	manClerk.~NameCard();
	manSENIOR.~NameCard();
	manAssist.~NameCard();
	Copy.ShowNameCardInfo();
	Copy1.ShowNameCardInfo();
	Copy2.ShowNameCardInfo();
}