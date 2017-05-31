/*
#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
	int k;
	long long n;
	while (cin >> n >> k) {
		int *arr = (int *)malloc(n * sizeof(int));
		long long i;
		for (i = 0;i < n;i++) {
			cin >> arr[i];
		}
		int *p = &arr[n-1];
		while (i > 0 && arr[i - 1] != k)i--;
		if (i == 0)cout << "No" << endl;
		else
			cout << i << ' ' << n - i + 1 << endl;

	}

	return 0;
}

*/