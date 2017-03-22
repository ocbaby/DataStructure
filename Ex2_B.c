#include<stdio.h>

int main()
{
	int stack[10];
	char c;
	int top=-1;
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='#')break;
		if(c>='0'&&c<='9')stack[++top]=c-'0';
		else
		{
			switch(c)
			{
				case '+':stack[top-1]+=stack[top--];break;
				case '-':stack[top-1]-=stack[top--];break;
				case '*':stack[top-1]*=stack[top--];break;
				case '/':stack[top-1]/=stack[top--];break;
			}



		}
	}

	printf("%d",stack[top]);
	return 0;

}
