#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <malloc.h>  
struct node  
{  
    int data;  
    struct node *l,*r;  
};  
struct node *p;  
int count=0;  
struct node *creat(struct node *p)  
{  
    char ch;  
    scanf("%c",&ch);  
    if (ch==',')  
        p = NULL;  
    else  
    {  
        p=(struct node*)malloc(sizeof(struct node));  
        p->data = ch;  
        p->l = creat(p->l);  
        p->r = creat(p->r);  
    }  
    return p;  
}  
void zhongxu(struct node *p)  
{  
    if (p)  
    {  
  
        zhongxu(p->l);  
        printf("%c",p->data);  
        zhongxu(p->r);  
  
    }  
}  
void houxu(struct node *p)  
{  
    if (p)  
    {  
  
        houxu(p->l);  
        houxu(p->r);  
        printf("%c",p->data);  
  
    }  
}  
int jiedian(struct node *p)  
{  
    if(p)  
    {  
        if((p->l==NULL)&&(p->r==NULL))  
            count++;  
        jiedian(p->l);  
        jiedian(p->r);  
    }  
    return 0;  
}  
int deep(struct node *p)  
{  
    int l1,r1;  
    if(!p)  
        return 0;  
    l1 = deep(p->l);  
    r1 = deep(p->r);  
    return l1>r1?l1+1:r1+1;  
}  
int main()  
{  
    struct node *root;  
    root = creat(p);  
    zhongxu(root);  
    printf("\n");  
    houxu(root);  
    printf("\n");  
    jiedian(root);  
    printf("%d\n",count);  
    printf("%d\n",deep(root));  
    return 0;  
}