#include<stdio.h>

int main()
{
	char stack[10];
	int top=-1;
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='#')break;
		if(c>='a'&&c<='z'){printf("%c",c);continue;}
		switch(c)
		{
			case '(':stack[++top]=c;break;
			case ')':while(stack[top]!='('&&top>=0)printf("%c",stack[top--]);if(stack[top]=='(')top--;break;
			case '+':
			case '-':while(stack[top]=='*'||stack[top]=='/')printf("%c",stack[top--]);stack[++top]=c;break;
			case '*':
			case '/':stack[++top]=c;break;
			default:printf("%c",c);
		}
	}
	while(top>=0)printf("%c",stack[top--]);
}
