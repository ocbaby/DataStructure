
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

typedef struct{
	int weight;
	int parent,lchild,rchild;
}HTNode, *HuffmanTree;

typedef char * *HuffmanCode;

void Select(HuffmanTree &HT,const int i,int &s1,int &s2){
	int k;
	for(k=1;k<=i;++k)
		if(HT[k].parent==0){s1=k++;break;}
	for(;k<=i;++k)
		if(HT[k].parent==0){s2=k++;break;}
	if (HT[s2].weight < HT[s1].weight) { int temp = s1;s1 = s2;s2 = temp; }
	for(;k<=i;++k){
		//cout<<k<<' '<<HT[k].weight<<' '<<s1<<' '<<s2<<' '<<endl;
		if(HT[k].parent==0&&HT[k].weight<=HT[s1].weight){ s2=s1;s1=k;}
		else if (HT[k].parent == 0 && HT[k].weight > HT[s1].weight&&HT[k].weight <= HT[s2].weight)s2 = k;
	}
	//if (HT[s2].weight < HT[s1].weight) { int temp = s1;s1 = s2;s2 = temp; }
	if (s1 > s2) { int temp = s2;s2 = s1;s1 = temp; }
}

//void Select()

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n){
	if(n<=1)return;
	int m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	HTNode *p;
	int i;
	for (p = HT + 1, i = 1;i <= n;++i, ++p, ++w)
	{
		(*p).weight = *w;
		(*p).parent = 0;(*p).lchild = 0;(*p).rchild = 0;
	}
	for (;i <= m;++i, ++p)
	{
		(*p).weight = 0;
		(*p).parent = 0;(*p).lchild = 0;(*p).rchild = 0;
	}
	for(i=n+1;i<=m;++i){
		int s1,s2;
		Select(HT,i-1,s1,s2);
		//cout << HT[5].parent << endl;
		//cout << endl << s1 << ' ' << s2 << endl;
		//cout << HT[5].weight << endl;
		HT[s1].parent=i;HT[s2].parent=i;
		HT[i].lchild=s1;HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	char *cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;++i){
		int start=n-1;
		for (int c = i, f = HT[i].parent;f != 0;c = f, f = HT[f].parent)
		{
			if (HT[f].lchild == c)	cd[--start] = '0';
			else cd[--start] = '1';
		}
		HC[i]=(char *)malloc((n-start)*sizeof(char));// ???
		strcpy_s(HC[i],n+1,&cd[start]);
	}
	free(cd);
}

int main(){
	string s;
	while(cin>>s){
		int la=s.length()*8;
		HuffmanTree Ht=NULL;
		HuffmanCode Hc;
		int count[256];
		memset(count,0,sizeof(count));
		unsigned int k;
		for(k=0;k<s.length();++k){
			count[s[k]]++;
		}
		int num = 0, i = 0;
		for(i=0;i<256;++i)
			if(count[i]>0)num++;
		int *w=(int *)malloc(num*sizeof(int));
		int *p=NULL;
		for(i=0,p=w;i<256;++i){
			if(count[i]>0){
				*p=count[i];
				++p;
			}
		}		

		HuffmanCoding(Ht,Hc,w,num);
		int lb=0;
		for (int i = 1;i <= num;++i)lb += w[i-1]*strlen(Hc[i]);
		//cout << endl << Hc[1] << endl << Hc[2] << endl << Hc[3] << endl << Hc[4] << endl << endl;
		
		cout << la << ' ' << lb << ' ';
		printf("%.1f\n",(float)la/lb);	
	}
	return 0;
}