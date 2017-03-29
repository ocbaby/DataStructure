#include<iostream>
using namespace std;

void move(int n,char pil_from,char pil_to,char pil_as)
{
	if(n==1)cout<<"Move disk 1 from "<<pil_from<<" to "<<pil_to<<endl;
	else 
	{
		move(n-1,pil_from,pil_as,pil_to);
		cout<<"Move disk "<<n<<" from "<<pil_from<<" to "<<pil_to<<endl;
		move(n-1,pil_as,pil_to,pil_from);
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		move(n,'A','C','B');
	}
	
	return 0;
}
