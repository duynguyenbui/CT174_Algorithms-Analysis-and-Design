#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char TenTien[25];
	int MG, PA;
} Tien;

Tien *ReadFromFile(int *n){
	FILE *f = fopen("ATM.inp", "r");
	Tien *dslt = (Tien*)malloc(sizeof(Tien));
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%d", &dslt[i].MG);
		fgets(dslt[i].TenTien, 25, f);
		dslt[i].TenTien[strlen(dslt[i].TenTien)-1] = '\0';
		dslt[i].PA = 0;
		i++;
		dslt = (Tien*)realloc(dslt, sizeof(Tien)*(i+1));
	}
	*n = i;
	fclose(f);
	return dslt;
}


void Swap(Tien *x, Tien *y){
	Tien Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}

void BubbleSort(Tien *dslt, int n){
	int i, j;
	for(i = 0; i < n; i++)
		for(j = n-1; j >= i+1; j--){
			if(dslt[j].MG > dslt[j-1].MG)
				Swap(&dslt[j], &dslt[j-1]);
		}
}

int count = 0;

void InDS(Tien *dslt, int n, int TienCanRut){
	int TongTienTra = 0;
	printf("| STT | Ten Loai Tien       | Menh Gia | So To | Thanh Tien |\n");
	int i, j = 0;
	for(i = 0; i < n; i++){
		printf("|%3d|", j+1);
		j++;
		printf("%25s|", dslt[i].TenTien);
		printf("%9d|", dslt[i].MG);
		printf("%9d|", dslt[i].PA);
		printf("%10d|\n", dslt[i].MG * dslt[i].PA);
		TongTienTra += dslt[i].MG * dslt[i].PA;
	}
	printf("Tong tien tra: %d\n", TongTienTra);
}


void greedy(Tien *dslt, int n, int TienCanRut){
	int i = 0; 
	count = 0;
	while(i < n && TienCanRut > 0){
		dslt[i].PA = TienCanRut / dslt[i].MG;
		count += dslt[i].PA;
		TienCanRut -= dslt[i].PA*dslt[i].MG;
		i++;
	}
}

int main(){
	int n;
	int TienCanRut;
	printf("Nhap so tien can rut: ");
	scanf("%d",&TienCanRut);
	Tien *dslt;
	dslt=ReadFromFile(&n);
	BubbleSort(dslt,n);
	greedy(dslt,n,TienCanRut);
	InDS(dslt,n,TienCanRut);
	free(dslt);
	return 0;
}
