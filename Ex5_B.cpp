#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef char ET;
char str[100];
int i,n;
typedef struct BiTNode
{
    ET data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int CreatrBiTree(BiTree  &T)
{
    if(i<n)
    {
        if(str[i++]==',')
            T=NULL;
        else
        {
            T=(BiTNode*)malloc(sizeof(BiTNode));
            if(!T)exit(-1);
            T->data=str[i-1];
            CreatrBiTree(T->lchild);
            CreatrBiTree(T->rchild);
        }
    }
    return 1;
}
void LeafCount(BiTree T,int &count)
{
    if(T)
    {
        if((!T->lchild)&&(!T->rchild))
        {
            count++;
        }
        LeafCount(T->lchild,count);
        LeafCount(T->rchild,count);
    }
}

int main()
{
    BiTree T;
    int count;
    while(~scanf("%s",str))
	{
	i=0;
	count=0;
    n=strlen(str);
    CreatrBiTree(T);
    LeafCount(T,count);
    printf("%d\n",count);
	}
    return 0;
}
