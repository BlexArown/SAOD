#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int A[], int n) {
	for (int i = 0; i < n; i++)
	A[i] = i+1;
}
void FillDec(int A[], int n) {
	for (int i = 0; i < n; i++)
	A[i] = n - i;
}
void FillRand(int A[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	A[i] = rand()%100;
}
int CheckSum(int A[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	sum += A[i];
	return sum;
}
int RunNumber(int A[], int n){
	int runs = 1;
	for (int i = 1; i < n; i++){
		if (A[i] < A[i-1]) runs++;
	}
	return runs;
}
void PrintMas(int A[], int n){
	for (int i = 0; i < n; i++)
	printf("%d ", A[i]);
	printf("\n");
}
void PrintB(int B[],int t){
	for (int i = 0; i < t; i++)
	printf("%d ", B[i]);
	printf("\n");
}
void SelectSort(int A[], int B[], int n) {
    int C=0;
    int M=0;
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            C++;
            if (A[j] < A[k]) {
                M++;
				k = j;
            }
        }
        if(A[i]!=A[k]){
            M++;
            int z = A[i];
            A[i] = A[k];
            A[k] = z;
        }
    }
	for (int i = 0; i < 6; i++){
		if(C!=0){
			if (i<3){
				B[i] = C;

			}
			B[i+3] = M;
		}
	}
	printf("Число сравнений:%d\n",C);
    printf("Число перемещений:%d\n",M);
    printf("Трудоемкость:%d\n",M+C);
}
int main(){
	int n = 10;
	int t = 6;
	int A[n];
	int B[t];
	FillInc(A,n);
	printf("Возрастающий массив: ");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	SelectSort(A,B,n);
	PrintB(B, t);
	printf("Сортировка возрастающего  массива:\n");
    PrintMas(A,n);
    printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	//
	FillDec(A,n);
	printf("\nУбывающий массив: ");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	SelectSort(A,B,n);
	PrintB(B, t);
	printf("\nСортировка убывающего массива:\n");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	//
	FillRand(A,n);
	printf("Случайный массив: ");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	SelectSort(A,B,n);
	printf("\nСортировка случайного  массива:\n");
    PrintMas(A,n);
    printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
}

