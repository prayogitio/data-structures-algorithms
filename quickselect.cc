#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r) {
	int x = arr[r];
	int i = l;
	for (int j = l; j < r; j++) {
		if (arr[j] <= x) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}

int quick_select(int arr[], int l, int r, int k) {
	if (k > 0 && k <= r-l+1) {
		int index = partition(arr, l, r);
		if (index-l == k-1)
			return arr[index];		
		if (index-l > k-1) 
			return quick_select(arr, l, index-1, k);
		return quick_select(arr, index+1, r, k-index+l-1);
	}
	return INT_MAX;
}

int main() {
	int arr[] = {10, 4, 5, 8, 6, 11, 26};
	int n = 7;
	int k = 3;
	printf("K-th smallest element is %d.\n", quick_select(arr, 0, n-1, k));
	return 0;
}