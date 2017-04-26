#include <stdio.h>
#include <stdlib.h>
 struct node
 {
     char data;
     struct node *lc,*rc;
 };
 char s[51];
 int c;
 struct node *CreateTree()
{
	struct node *root;
	char x;
	x=s[c++];

	if(x==',')
		return NULL;
	else
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->data=x;
        root->lc=CreateTree();
        root->rc=CreateTree();
	}
return root;
}
void InOrder(struct node *root)
 {
     if(root!=NULL)
     {
        InOrder(root->lc);
        printf("%c",root->data);
        InOrder(root->rc);
     }
 }
 void PostOrder(struct node *root)
 {
     if(root!=NULL)
     {
        PostOrder(root->lc);
        PostOrder(root->rc);
        printf("%c",root->data);
     }
 }
 int main()
 {
     while(~scanf("%s",s))
     {
         c=0;
         struct node *root;
         root=(struct node *)malloc(sizeof(struct node));
         root=CreateTree();
         InOrder(root);
         printf("\n");
         PostOrder(root);
         printf("\n");
     }
	 return 0;
 }
