#include<iostream>
#include<stack>
using namespace std;


int main()
{
	stack<int> stk;
	char c;
	while(cin>>c)
	{
		if(c=='#')break;
		if(c>='0'&&c<='9')stk.push(c-'0');
		else{
			//if(stk.empty()){cerr<<"Invalid input!"<<endl;break;}
			int t1=stk.top();stk.pop();
			int t2=stk.top();stk.pop();
			switch(c){
				case '+':stk.push(t2+t1);break;
				case '-':stk.push(t2-t1);break;
				case '*':stk.push(t2*t1);break;
				case '/':stk.push(t2/t1);break;
			}

		}
	}
	cout<<stk.top()<<endl;

	return 0;
}
