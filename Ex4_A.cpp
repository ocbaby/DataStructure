#include<iostream>
#include<vector>
using namespace std;

/*
struct Element{
	int i;
	int j;
	int e;
	ElemPtr row_next;
	ElemPtr col_next;
}Element,*ElemPtr;
*/

void printMat(vector<vector<int> > &mat){
	for(vector<vector<int> >::iterator row=mat.begin();row!=mat.end();row++)
	{
		for(vector<int>::iterator col=(*row).begin();col!=(*row).end();col++)
		{
			cout<<*col;
			if(col+1!=(*row).end())cout<<' ';
		}
		cout<<endl;
	}


}

void inputMat(vector<vector<int> > &mat){
	for(vector<vector<int> >::iterator row=mat.begin();row!=mat.end();row++)
	{
		for(vector<int>::iterator col=(*row).begin();col!=(*row).end();col++)
		{
			cin>>(*col);
		}
	}
}

void reverseMat(vector<vector<int> > &mat,vector<vector<int> > &result){
	for(int i=0;i<mat.size();i++)
		for(int j=0;j<mat[i].size();j++)
			result[j][i]=mat[i][j];
}


int main(){
	int rows=0,cols=0;
	while(cin>>rows>>cols)
	{
		vector<vector<int> > mat(rows,vector<int>(cols));
		vector<vector<int> > result(cols,vector<int>(rows));
		inputMat(mat);
		reverseMat(mat,result);
		printMat(result);	
		cout<<endl;
	}
	
	return 0;
}
