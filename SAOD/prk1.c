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
int main(){
	int n = 10;
	int A[n];
	FillInc(A,n);
	printf("Возрастающий массив: ");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	FillDec(A,n);
	printf("Убывающий массив: ");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
	FillRand(A,n);
	printf("Случайный массив: ");
	PrintMas(A,n);
	printf("Серий: %d, Сумма: %d\n", RunNumber(A,n), CheckSum(A,n));
}

