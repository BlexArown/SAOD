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
void SelectSort(int A[], int n) {
    int C=0;
    int M=0;
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            C++;
            if (A[j] < A[k]) {
                k = j;
            }
        }
        if(A[i]!=A[k]){ // против фиктивность
            M++;
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
        }
    }
    printf("Число сравнений:%d\n",C);
    printf("Число перемещений:%d\n",M);
    printf("Трудоемкость:%d\n",M+C);
}
int main(){
	int n = 10;
	int A[n];
	FillInc(A,n);
	printf("Возрастающий массив: ");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	SelectSort(A,n);
	printf("\nСортировка возрастающего  массива:\n");
        PrintMas(A,n);
        printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	//
	FillDec(A,n);
	printf("Убывающий массив: ");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	SelectSort(A,n);
	printf("\nСортировка убывающего массива:\n");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	//
	FillRand(A,n);
	printf("Случайный массив: ");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	SelectSort(A,n);
	printf("\nСортировка случайного  массива:\n");
        PrintMas(A,n);
        printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	return 0;
}

