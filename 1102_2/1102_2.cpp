#include "BoundCheck2DIntArray.h"

int main()
{
	BoundCheck2DIntArray parr(3, 4);
	for (int i = 0; i < parr.GetArrRow(); i++)
	{
		for (int k = 0; k < parr.GetArrCol(); k++)
		{
			parr[i][k] = ((parr.GetArrCol())*i) + k+1;
		}
	}
	
	for (int i = 0; i < parr.GetArrRow(); i++)
	{
		for (int k = 0; k < parr.GetArrCol(); k++)
		{
			if (k != 0)
			{
				cout<<"\t";
			}
			cout << parr[i][k];
		}
		cout << endl;
	}
}