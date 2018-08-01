#include "Printer.h"

void Printer::SetString(const char * save)
{
	strcpy_s(string, save);
}
void Printer::ShowString()
{
	cout << string << endl;
}
