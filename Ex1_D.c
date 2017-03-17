
#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;


Status InitList(LinkList L)
{
	L->next = NULL;
	int temp = -1;
	scanf("%d", &temp);
	while ( temp != -1)
	{
		LNode*p = L;
		while (p->next != NULL)p = p->next;
		p->next = (LNode*)malloc(sizeof(LNode));
		p->next->data = temp;
		p->next->next = NULL;
		scanf("%d", &temp);
	}
	return OK;
}

Status CvtList(LinkList L)
{
	if (L->next != NULL)
	{
		LNode *p = L->next;
		LNode *q = p;
		while (q=p->next)
		{
			p->next = q->next;
			q->next = L->next;
			L->next = q;
		}
	}
	return OK;
}




Status DispList(LinkList L)
{
	LNode *p = L;
	while (p->next != NULL)
	{
		p = p->next;
		if (p->next != NULL)
			printf("%d ", p->data);
		else
			printf("%d", p->data);
	}
	printf("\n");
	return OK;
}


int main()
{
	LinkList L = (LinkList)malloc(sizeof(LNode));
	InitList(L);
	CvtList(L);
	DispList(L);
	return 0;
}