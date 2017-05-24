#include<iostream>

using namespace std;

int main() {
	int a[101];
	int t, n, m, i, u, v;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0;i <= n;i++) {
			a[i] = i;
		}
		for (i = 0;i < m;i++) {
			cin >> u >> v;
			while (u != a[u])
				u = a[u];
			while (v != a[v])
				v = a[v];
			if (u != v)
				a[u] = v;
		}
		int k = 0;
		for (i = 1;i <= n;i++) {
			if (a[i] == i)
				k++;
		}
		cout << k << endl;
	}

	return 0;
}