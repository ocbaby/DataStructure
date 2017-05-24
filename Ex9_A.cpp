/*

#include<iostream>
#include<cstring>
#include<cstdlib>

//#define MAX_SIZE 101;

using namespace std;

int a[104][104];
int visit[104];
int link[104];
int tp, op;

void BFS(int n) {
	op++;
	for (int i = 0;i < 104;++i) {
		if (a[n][i] == 1 && visit[i] == 1) {
			link[tp++] = i;
			visit[i] = 0;
		}
	}
	if (op <= tp)
		BFS(link[op]);
}

int main() {
	int n, k, m, t, i;
	cin >> n;
	while (n--) {
		memset(a, 0, sizeof(a));
		for (i = 0;i < 104;++i)
			visit[i] = 1;
		tp = op = 0;
		cin >> k >> m >> t;
		for (i = 0;i < m;++i) {
			int u, v;
			cin >> u >> v;
			a[u][v] = a[v][u] = 1;
		}
		link[tp++] = t;
		visit[t] = 0;
		BFS(t);
		for (i = 0;i < tp;++i) {
			cout << link[i];
			if (i == tp - 1)
				cout << endl;
			else cout << ' ';
		}
	}
//	cin.get();cin.get();cin.get();cin.get();
	return 0;
}

*/