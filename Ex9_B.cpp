/*

#include <iostream>  
#include <cstdlib>  
#include <cstring>  
#include <stdbool.h>
using namespace std;
const int MAXN = 100 + 10;
int k, m, t;
bool vis[MAXN];
int head[MAXN];
int cnt;
struct node
{
	int v;
	int next;
}edge[5000];

void add(int u, int v)
{
	edge[cnt].v = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

bool check(int u, int v)
{
	for (int i = head[u];i != -1;i = edge[i].next)
	{
		if (edge[i].v == v)return 1;
	}
	return 0;
}

void BFS(int s,int *&lp)
{
	memset(vis, 0, sizeof(vis));
	int q[110];
	int qhead = 0, qtail = 0;
	vis[s] = 1;
	q[qtail++] = s;
	while (qhead<qtail)
	{
		int temp = q[qhead++];
		*lp = temp;
		lp++;
		for (int i = 0;i<k;++i)
		{
			if (!vis[i] && check(temp, i))
			{
				vis[i] = 1;
				q[qtail++] = i;
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> k >> m >> t;
		memset(head, -1, sizeof(head));
		int u, v;
		cnt = 0;
		for (int i = 0;i<m;++i)
		{
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		int *link = (int*)malloc(k * sizeof(int));
		int *lp = link;
		BFS(t,lp);
		for (int i = 0;i < k;++i) {
			cout << link[i];
			if (i <= k - 1)
				cout << ' ';
			else cout << endl;
		}
		
	}
	return 0;
}

*/