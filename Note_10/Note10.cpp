#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <iostream>

typedef struct NODE
{
	int data;
	NODE *link;
}NODE;

NODE* Create_Node(int data)
{
	NODE *New_Node = (NODE*)malloc(sizeof(NODE));
	if (New_Node == NULL)
	{
		puts("메모리 할당 에러");
		exit(1);
	}

	New_Node->data = data;
	New_Node->link = NULL;

	return New_Node;
}

void Insert_Node(NODE **pHead, NODE *p, NODE *New_Node)
{
	if (*pHead == NULL)
	{
		*pHead = New_Node;
	}
	else if (p == NULL)
	{
		New_Node->link = *pHead;
		*pHead = New_Node;
	}
	else
	{
		New_Node->link = p->link;
		p->link = New_Node;
	}
}

void Display_Node(NODE *list)
{
	NODE *p = list;

	while (p != NULL)
	{
		printf("%d-> ", p->data);
		p = p->link;
	}
	printf("\n");
}

NODE* Search_Node(NODE *list, int data)
{
	NODE *p = list;

	while (p != NULL)
	{
		if (p->data == data)
			return p;

		p = p->link;
	}

	return NULL;
}

int Remove_Node(NODE *list, int data)
{
	NODE *p = list;
	NODE *remove;

	while (p != NULL)
	{
		if (p->link != NULL) // 삭제될 선행 노드를 찾는다.
		{
			if (p->link->data == data)
				break;
		}
		p = p->link;
	}

	if (p != NULL)
	{
		remove = p->link; // 삭제될 노드를 remove가 가리키게 한다.
		p->link = remove->link;
		free(remove);
		return 0;
	}
	else
		return -1;
}

NODE* Reverse(NODE *list)
{
	NODE *p, *q, *r;
	p = list; // 역순으로 만들 리스트
	q = NULL; // 역순으로 만들 노드

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	return q;
}

class A
{
public:
	A()
	{
		a = 5;
	}
	virtual int getA() { return a; }
	int a;
};

class B : public A
{
public:
	B()
	{
		A::a = 3;
	}
	int getA() { return a; }
};


int main()
{
	//NODE *list = NULL;
	//NODE *p = NULL;
	//NODE *recv_list = NULL;

	//Insert_Node(&list, NULL, Create_Node(10)); // 10->
	//Insert_Node(&list, NULL, Create_Node(20)); // 20->10
	//Insert_Node(&list, NULL, Create_Node(30)); // 30->20->10
	//Insert_Node(&list, NULL, Create_Node(40)); // 40->30->20->10
	//Insert_Node(&list, NULL, Create_Node(50)); // 50->40->30->20->10

	//Display_Node(list);// 50->40->30->20->10

	//p = Search_Node(list, 30); // 데이터가 10인 노드 검색

	//Insert_Node(&list, p, Create_Node(5)); // 검색된 p 노드 다음에 추가 

	//Display_Node(list); // 50->40->30->20->10->5

	//Remove_Node(list, 30); // 데이터가 30인 노드 삭제

	//Display_Node(list);  // 60->50->40->20->15->10->5

	//recv_list = Reverse(list); // 연결리스트 역순

	//Display_Node(recv_list); // 5-> 10-> 20-> 40-> 50->
	

	int * a = new int[3];
	_msize(a);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;

	return 0;
}