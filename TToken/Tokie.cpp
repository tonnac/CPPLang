#include "TToken.h"



int main()
{
	char ch[] = "qjwqenk Akjqnew MKJEWN";
	TToken tk(ch);
	TValue * go = tk.GetTValue();
	cout << go;
	return 0;
}