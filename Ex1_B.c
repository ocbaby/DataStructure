
#include<stdio.h>
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;


Status InitList(LinkList L, int n)
{
	L->next = NULL;
	int i = 0;
	for (i = 0;i<n;i++)
	{
		LNode*p = L;
		while (p->next != NULL)p = p->next;
		p->next = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &(p->next->data));
		p->next->next = NULL;
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
	int length = 0;
	scanf("%d", &length);
	InitList(L, length);
	DispList(L);
	return 0;
}

/***************************************************
User name: 201400820188ÀîÔ´¶«
Result: Accepted
Take time: 0ms
Take Memory: 104KB
Submit time: 2017-03-15 15:28:11
****************************************************/