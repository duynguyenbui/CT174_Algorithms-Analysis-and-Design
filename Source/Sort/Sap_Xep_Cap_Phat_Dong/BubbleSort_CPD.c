#include <stdio.h>

typedef int keytype;
typedef float othertype;
typedef struct {
	keytype key;
	othertype otherfields;
} recordtype;

void Swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(recordtype a[], int n){
	int i, j;
	for(i = 0; i < n-1; i++)
		for(j = n-1; j > i; j--)
			if(a[j].key < a[j-1].key)
				Swap(&a[j], &a[j-1]);
}

void Read_Data(recordtype a[], int *n){
	FILE *f;
	f = fopen("data.txt", "r");
	int i = 0;
	if(f != NULL)
		while(!feof(f)){
			fscanf(f, "%d%f", &a[i].key, &a[i].otherfields);
			i++;
		}
	else
		printf("Loi mo file!!!");
	fclose(f);
	*n = i;
}

void Print_Data(recordtype a[], int n){
	int i;
	for(i=0;i<n;i++) 
	printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].otherfields);
}

int main(){
	recordtype a[100];
	int n;
	printf("Thuat toan sap xep Bubble Sort\n\n");
	Read_Data(a, &n);
	printf("Day so truoc khi sap xep: \n");
	Print_Data(a, n);
	BubbleSort(a, n);
	printf("Day so sau khi sap xep: \n");
	Print_Data(a, n);
}
