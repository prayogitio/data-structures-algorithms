#include <cstdio>
#include <cstring>
using namespace std;

void count_sort(int arr[]) {
	int res[10];
	int count[10+1];
	memset(count, 0, sizeof count);
	for (int i = 0; i < 10; i++) {
		++count[arr[i]];
	}
	for (int i = 1; i < 10; i++) {
		count[i] += count[i-1];
	}
	for (int i = 0; i < 10; i++) {
		res[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}
	for (int i = 0; i < 10; i++) {
		arr[i] = res[i];
	}
}

int main() {
	int arr[] = {0,9,8,7,6,5,4,3,2,1};
	count_sort(arr);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}