/*

#include<iostream>

using namespace std;

int a[100000];

void sort(int left, int right) {
	int key = a[left];
	int i = left, j = right;
	while (i < j) {
		while (i < j&&key <= a[j])j--;
		a[i] = a[j];
		while (i < j&&key >= a[i])i++;
		a[j] = a[i];
	}
	a[i] = key;
	if (left < right) {
		sort(left, i - 1);
		sort(i + 1, right);
	}
}

int main() {
	int n;
	while (cin >> n) {
		int i;
		for (i = 0;i < n;i++)
			cin >> a[i];
		sort(0, n - 1);
		for (i = 0;i < n - 1;i++)
			cout << a[i] << (char)' ';
		cout << a[n - 1] << endl;
	}
}

*/