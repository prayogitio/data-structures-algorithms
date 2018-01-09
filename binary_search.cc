#include <cstdio>
using namespace std;

//This is the true form of binary search. Prajogo Tio approves. Well done son well done. Everything is well done.

int binary_search_upper_bound(int arr[], int lo, int hi, int val) {
	while (lo <= hi) {
		int mid = lo + (hi-lo)/2;
		if (val < arr[mid])
			hi = mid - 1;
		else lo = mid + 1;
	}
	return hi;
}

int binary_search_lower_bound(int arr[], int lo, int hi, int val) {
	while (lo <= hi) {
		int mid = lo + (hi-lo)/2;
		if (val <= arr[mid])
			hi = mid - 1;
		else lo = mid + 1;
	}
	return lo;
}

int main() {
	int arr[] = {3,4,5,12};
	int N = 4;
	int lo = 0;
	int hi = N-1;
	int val = 4.5;
	int res = binary_search_upper_bound(arr, lo, hi, val);
	printf("%d\n", res);		
	res = binary_search_lower_bound(arr, lo, hi, val);
	printf("%d\n", res);
	return 0;
}