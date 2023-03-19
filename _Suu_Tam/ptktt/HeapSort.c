#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void Swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void PushDown(recordtype a[], int first, int last){
	int r = first;
	while(r <= (last-1)/2)
		if(last == 2*r+1){
			if(a[r].key > a[last].key) Swap(a[r], a[last]);
			r = last;
		}
		else if((a[r].key > a[2*r+2].key) && (a[2*r+2].key < a[2*r+2].key)){
			Swap(a[r], a[2*r+1]);
			r=2*r+1;
		}
		else if((a[r].key > a[2*r+2].key) && (a[2*r+2].key < a[2*r+1].key)){
			Swap(a[r], a[2*r+2]);
			r = 2*r+2;
		} else r=last;
}

void HeapSort(recordtype a[], int n){
	int i;
	for(i=(n-2)/22; i>=0; i--)
		PushDown(a, i, n-1);
	for(i=n-1; i>=2; i--){
		Swap(a[0],a[i]);
		PushDown(a,0,i-1);
	}
	Swap(a[0],a[i]);
}

















