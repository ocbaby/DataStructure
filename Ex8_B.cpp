#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct Node{
	int data;
	Node* next;
}Node,*Graph;

void checkGraph(const Graph &graph,const int a,const int b,int &tag){
	Node *p=&graph[a];
	while(p=p->next){
		if(p->data==b){
			tag=1;return;
		}
	}
}


// Runtime Error
void freeLink(Node *&next){
	if (next != NULL)freeLink(next->next);
	free(next);
}

void freeGraph(Graph &graph,int n) {
	for (int i = 0;i < n;i++) {
		Node* p = &graph[i];
		freeLink(p);
	}

}


int main(){
	int n=0,m=0;
	while(cin>>n>>m){
		// Initialize the graph.
		Graph graph = (Graph)malloc(n * sizeof(Node));
		for(int i=0;i<n;i++){
			graph[i].data=i;
			graph[i].next=NULL;
		}
		// Input the graph.
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			Node *p=&graph[u];
			while(p->next)p=p->next;
			p->next=(Node*)malloc(sizeof(Node));
			p->next->data=v;
			p->next->next = NULL;
		}
		// Answer requests.
		int q;
		cin>>q;
		for(int i=0;i<q;i++){
			int a,b;
			cin>>a>>b;
			int tag=0;
			checkGraph(graph,a,b,tag);
			cout<<(tag==1?"Yes":"No")<<endl;
		}
		free(graph);
		//freeGraph(graph,n);
	}

	return 0;

}
