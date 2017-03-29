#include<iostream>

using namespace std;

int calc(int a)
{
	if(a==0)return 1;
	else
		return a*calc(a-1);

}

int main()
{
	int a;
	while(cin>>a)
	{
		cout<<calc(a)<<endl;
	}
	return 0;
}
