#include <cstdio>
using namespace std;

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j) {
            quickSort(arr, left, j);
      }
      if (i < right) {
            quickSort(arr, i, right);
      }
      for(int i=0;i<10;i++) {
      	printf("%d ",arr[i]);
      }
      printf("\n");
}

int main() {
	int data[10];
	for (int i=0;i<10;i++) {
		scanf("%d ", &data[i]);
	}
	quickSort(data, 0,9);
	return 0;
}
