
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

struct Tree{
	char data;
	Tree *lt,*rt;
};

void construct(Tree *&root,string pre, string in)
{
	if(pre.empty())return;
	if(in.empty())return;
	root=(Tree *)malloc(sizeof(Tree));
	root->data=pre[0];
	if(in.find(pre[0])==0)root->lt=NULL;
	else
		construct(root->lt,pre.substr(1,in.find(pre[0])),in.substr(0,in.find(pre[0])-1));
	if(in.find(pre[0])==in.length()-1)root->rt=NULL;
	else
		construct(root->rt,pre.substr(in.find(pre[0])+1),in.substr(in.find(pre[0])+1));
}

int deep(Tree *root)
{
	int d=0;
	if(root==NULL)return 0;
	d++;
	int l=d,r=d;
	l=deep(root->lt);
	r=deep(root->rt);
	d += (l > r ? l : r);
	return d;
}


int main()
{
	int N;
	while(cin>>N)
	{
		cin.get();
		string pre, in;
		getline(cin,pre);
		getline(cin,in);
		Tree *root;
		construct(root,pre,in);
		cout<<deep(root)<<endl;
	}
	return 0;
}
