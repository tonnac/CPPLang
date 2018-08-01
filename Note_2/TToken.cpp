#include "TToken.h"



TToken::TToken(char * data) : iCounter(0)
{
	char * temp;
	temp = strtok(data, SPACE);	
	tValue = new TValue(temp);
	TValue * temp1 = tValue;
	for (iCounter;
		(temp = strtok(NULL, SPACE));
		iCounter++)
	{
		std::cout << temp1->pChar << std::endl;
		temp1->pNext = new TValue(temp);
		temp1 = temp1->pNext;
	}

	
}


TToken::~TToken()
{
	TValue * temp = tValue;
	TValue * temp1 = tValue;
	/*while (1)
	{
		if (temp->pNext != NULL)
		{
			temp1 = temp;
			temp = temp->pNext;
			continue;
		}
		delete temp;
		if (temp == tValue)
		{
			break;
		}
		temp1->pNext = NULL;
		temp1 = tValue;
		temp = tValue;
	}*/
	while (temp != 0)
	{
		temp1 = temp;
		temp = temp->pNext;
		delete temp1;
	}
}
