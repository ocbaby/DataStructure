/*

#include<iostream>

using namespace std;

int a[100000];
int b[100000];

void quick_sort(int left, int right,int &q_swaptime) {
	int key = a[left];
	int i = left, j = right;
	while (i < j) {
		while (i < j&&key <= a[j])j--;
		if (a[i] != a[j])q_swaptime++;
		a[i] = a[j];
		while (i < j&&key >= a[i])i++;
		if (a[i] != a[j])q_swaptime++;
		a[j] = a[i];
	}
	a[i] = key;
	if (left < right) {
		quick_sort(left, i - 1,q_swaptime);
		quick_sort(i + 1, right,q_swaptime);
	}
}

void bubble_sort(int left, int right,int &b_swaptime) {
	for (int i = left;i <= right;i++) {
		for (int j = i;j <= right;j++) {
			if (b[i] > b[j]) {
				b_swaptime++;
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
}

int main() {
	int n;
	while (cin >> n) {
		for (int i = 0;i < n;i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		int q_t = 0, b_t = 0;
		quick_sort(0, n - 1, q_t);
		bubble_sort(0, n - 1, b_t);
		cout << b_t << char(' ') << q_t << endl;
	}
}

*/