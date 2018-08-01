#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char * MakeStarAdr(int len)
{
	char * str = (char*)malloc(sizeof(char)*len);
	return str;
}

int main()
{
	char * str = MakeStarAdr(20);
	strcpy(str, "i am so happy~");
	cout << str << endl;
	free(str);
	return 0;
}