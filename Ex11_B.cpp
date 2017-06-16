#include<iostream>

using namespace std;

int a[100001],temp[100001];
long long sum;

void merge(int l, int r, int m) {
	int i = l, j = m + 1, k = l;
	while (i <= m&&j <= r) {
		if (a[i] > a[j]) {
			sum += m - i + 1;
			temp[k++] = a[j++];
		}
		else {
			temp[k++] = a[i++];
		}
	}
	while (i <= m) {
		temp[k++] = a[i++];
	}
	while (j <= r) {
		temp[k++] = a[j++];
	}
	for (i = l; i <= r;i++) {
		a[i] = temp[i];
	}
}


void mergesort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergesort(l, m);
		mergesort(m + 1, r);
		merge(l, r, m);
	}
}


int main() {
	int n;
	while (cin >> n) {
		for (int i = 0;i < n;i++) {
			cin >> a[i];
		}
		sum = 0;
		mergesort(0, n - 1);
		cout << sum << endl;
	}

}
