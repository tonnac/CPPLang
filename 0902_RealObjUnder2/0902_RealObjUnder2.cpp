#include <iostream>
using namespace std;

typedef struct Data
{
	int data;
	void(*qqq)(Data*);
	void(*Sub)(Data*, int);
}Data;

void ShowData(Data* THIS) { cout << "Data: " << THIS->data << endl; }
void Add(Data* THIS, int num) { THIS->data += num; }

int main()
{
	Data obj1 = { 15,ShowData,Add };
	Data obj2 = { 7,ShowData,Add };

	obj1.Sub(&obj1, 17);
	obj2.Sub(&obj2, 9);
	obj1.qqq(&obj1);
	obj2.qqq(&obj2);
}