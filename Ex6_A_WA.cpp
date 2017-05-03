/*
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;

typedef struct Node{
	char data;
	struct Node *lchild;
	struct Node *rchild;
} BiTreeNode,*NodePtr;

void constructTree(NodePtr &root, string &preTree)
{
	if(preTree[0]=='\0')return;
	if(preTree[0]==',')
	{
		root=NULL;
		preTree.erase(0,1);
		return;
	}
	else
	{
		root=(NodePtr)malloc(sizeof(BiTreeNode));
		root->data=preTree[0];
		preTree.erase(0,1);
		constructTree(root->lchild,preTree);
		constructTree(root->rchild,preTree);
	}
}

void levelDispart(vector<vector<char> > &list,NodePtr root,unsigned int floor)
{
	if(root==NULL)return;
	else
	{
		if (list.size() < floor + 1)
		{
			vector<char> temp(1, root->data);
			list.push_back(temp);
		}
		else
			list[floor].push_back(root->data);
		levelDispart(list, root->lchild, floor + 1);
		levelDispart(list, root->rchild, floor + 1);
	}
}

void treePrint(const vector<vector<char> > &list)
{
	for(int i=0;i<list.size();i++)
	{
		for(int j=0;j<list[i].size();j++)
		{
			cout << list[i][j];
		}
	}
	//cout << endl;
}

int main()
{
	int num;
	cin >> num;
	
		cin.get();
		for(int n=0;n<num;n++)
		{
			NodePtr root=NULL;
			string preTree;
			getline(cin,preTree);
			//cout << "hahahahhaha";
			constructTree(root,preTree);
			if(root==NULL){cout<<endl;continue;}
			vector<vector<char> > list;
			levelDispart(list,root,0);
			treePrint(list);
			cout<<endl;
		}
	
	return 0;
}
*/