#include <cstdio>
#include <algorithm>
using namespace std;

int insertion_sort(int data[]){
	for (int j=1;j<10;j++){
		int key = data[j];
		int i = j-1;
		while (i >= 0 && data[i] > key){
			data[i+1] = data[i];
			i--;
		}
		data[i+1]=key;
	}
	return data[10];
}

int main() {
	int data[10];
	for (int i=0;i<10;i++){
		scanf("%d ",&data[i]);
	}
	data[10] = insertion_sort(data);
	for (int i=0;i<10;i++){
		printf("%d ",data[i]);
	}

	return 0;
}