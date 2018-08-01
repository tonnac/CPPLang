#include "KKK.h"


void Plus(int* ptr)
{
	ptr++;
}

int main()
{
	int num = 1;
	int * ptr = &num;

	Plus(ptr);

}
