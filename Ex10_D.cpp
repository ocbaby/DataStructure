#include <iostream>
#include <cstdio>
using namespace std;

struct Tree
{
	int x;
	Tree *lt, *rt;
};

void insert(Tree *&root, int e)
{
	if (!root)
	{
		Tree *r = new Tree;
		r->x = e;
		r->lt = r->rt = NULL;
		root = r;
	}
	else
	{
		if (e<root->x)
			insert(root->lt, e);
		else if (e>root->x)
			insert(root->rt, e);
	}
}

bool cmp(Tree *r, Tree *r2)
{
	if (r == NULL&&r2 == NULL)
		return true;
	else if (r == NULL || r2 == NULL)
		return false;
	if (r->x != r2->x)
		return false;
	return cmp(r->lt, r2->lt) && cmp(r->rt, r2->rt);
}

int main()
{
	int n, l;
	while (scanf("%d", &n), n != 0)
	{
		scanf("%d", &l);
		Tree *root = NULL;
		int i;
		for (i = 1;i <= n;i++)
		{
			int e;
			scanf("%d", &e);
			insert(root, e);
		}
		int j;
		for (j = 1;j <= l;j++)
		{
			Tree *r2 = NULL;
			for (i = 1;i <= n;i++)
			{
				int e;
				scanf("%d", &e);
				insert(r2, e);
			}
			if (cmp(root, r2))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}

/***************************************************
User name: ***
Result: Accepted
Take time: 0ms
Take Memory: 152KB
Submit time: 2016-11-29 16:54:54
****************************************************/