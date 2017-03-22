#include<stdio.h>

int main()
{
	int stack[20], top=-1;
	int n,r;
	
	scanf("%d",&n);
	scanf("%d",&r);
	
	if(n==0)
	{
		printf("0\n");
		return 0;
	}
	
	while(n)
	{
		stack[++top]=n%r;
		n=n/r;
	}

	while(top!=-1)
	{
		printf("%d",stack[top--]);
	}

	return 0;

}
