#include<iostream>
#include<stdlib.h>
#include<stdio.h>

//using namespace std;

int main() {
	int n, m;
	//cin >> n >> m;
	while (scanf("%d %d", &n, &m) != EOF) {

		//int *arr = (int *)malloc(n * sizeof(int));
		int arr[1000004];
		for (int i = 0;i < n;i++)
			//cin >> arr[i];
			scanf("%d", &arr[i]);

		for (int i = 0;i < m;i++) {
			int low = 0, high = n - 1, mid;
			int key;
			//cin >> key;
			scanf("%d", &key);

/*
		int last = 0;
		if (key >= arr[last])
			low = last;
		else
			high = last;
*/

			//low = last;

			int flag = 1;

			while (low <= high) {
				mid = (low + high ) / 2;
				if (key == arr[mid]) {
					//cout << mid << endl;
					printf("%d\n", mid);
//					last = mid;
					flag = 0;
					break;
				}
				else if (key < arr[mid]) {
					high = mid - 1;
				}
				else if (key > arr[mid]) {
					low = mid + 1;
				}
			}
			if (flag)
				printf("-1\n");
		}
	}
	return 0;
}
