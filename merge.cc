#include <cstdio>
using namespace std;
void merge(int a[],int p,int q,int r);
void merge_sort(int data[], int first, int last);

void merge_sort(int data[], int first, int last) {
	if (first < last){
		int middle = first + (last - first)/2;
		merge_sort(data,first,middle);
		merge_sort(data,middle+1,last);	
		merge(data,first,middle,last);
	}
}

void merge(int a[],int p,int q,int r) {
	int c[7];
	int i=p;
	int j=q+1;
	int k=p;
	while((i<=q)&&(j<=r)) {
		if(a[i]<a[j]) {
		    c[k]=a[i];
		    i=i+1;
		    k=k+1;
		}
		else {
		    c[k]=a[j];
		    j=j+1;
		    k=k+1;
		}
	}
	while(i<=q) {
	    c[k] =a[i];
	    i=i+1;
	    k=k+1;
	}
	while(j<=r) {
	    c[k]=a[j];
	    j=j+1;
        k=k+1;
	}
	int l = p;
	while(l<=r) {
		a[l]=c[l];
		l=l+1;
	}
	for (int i=0;i<7;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int data[7];
	for (int i=0;i<7;i++) {
		scanf("%d ",&data[i]);
	}
	merge_sort(data,0,7);
}