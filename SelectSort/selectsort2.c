#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        A[i] = i + 1;
    }
}

void FillDec(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        A[i] = n - i;
    }
}

void FillRand(int n, int A[]) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
    }
}

int CheckSum(int n, int A[]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

int RunNumber(int n, int A[]) {
    if (n == 0) return 0;
    int series = 1;
    for (int i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            series++;
        }
    }
    return series;
}

void PrintMas(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int SelectSort(int n, int A[]) {
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
            M++;
            int temp = A[i];
            M++;
            A[i] = A[k];
            M++;
            A[k] = temp;
    }
    int trud=M+C;
    return trud;
}

int updateSelectSort(int n, int A[]) {
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
        if(A[i]!=A[k]){ // защита от фиктивности
            M++;
            int temp = A[i];
            M++;
            A[i] = A[k];
            M++;
            A[k] = temp;
        }
    }
    int trud=M+C;
    return trud;
}

void printData(int n, int A[]) {
    int Tteor = ((n*(n-1)) / 2) + (3 * (n - 1));
    printf("%-5d | %-9d |", n, Tteor);
    FillDec(n, A);
    int trud = SelectSort(n, A);
    printf(" %-5d |", trud);
    FillRand(n, A);
    trud = SelectSort(n, A);
    printf(" %-5d |", trud);
    FillInc(n, A);
    trud = SelectSort(n, A);
    printf(" %-5d |", trud);
    FillDec(n, A);
    trud = updateSelectSort(n, A);
    printf(" %-5d |", trud);
    FillRand(n, A);
    trud = updateSelectSort(n, A);
    printf(" %-5d |", trud);
    FillInc(n, A);
    trud = updateSelectSort(n, A);
    printf(" %-5d |\n", trud);
}

int main() {
    int n = 10;
    int A[n];
    printf("   N  |  M+C теор |     Исходный Mф+Сф    |    Улучшенный Mф+Сф   |\n");
    printf("      |           | убыв  | случ  | возр  | убыв  | случ  | возр  |\n");
    printf("------+-----------+--------+------+-------+-------+-------+-------+\n");
    printData(n, A);
    n = 100;
    printData(n, A);
    return 0;
}
