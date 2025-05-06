#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10

int MyArray[N];
int m = 0, c = 0;

void FillRand(int n) {
    for (int i = 0; i < n; i++) {
        MyArray[i] = rand() % 1000 + 1;
    }
}

void FillInc(int n) {
    for (int i = 0; i < n; i++) {
        MyArray[i] = i;
    }
}

void FillDec(int n) {
    for (int i = 0; i < n; i++) {
        MyArray[i] = n - i;
    }
}

void PrintArray(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", MyArray[i]);
    }
    printf("\n");
}

int CheckSum(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += MyArray[i];
    }
    return sum;
}

int RunNumber(int n) {
    int series = 1;
    for (int i = 0; i < n - 1; i++) {
        if (MyArray[i] > MyArray[i + 1]) {
            series++;
        }
    }
    return series;
}

void Reset() {
    m = 0;
    c = 0;
}

void ShellSort(int n) {
    for (int h = n / 2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            int temp = MyArray[i];
            int j;
            for (j = i; j >= h; j -= h) {
                c++;
                if (MyArray[j - h] > temp) {
                    MyArray[j] = MyArray[j - h];
                    m++;
                } else {
                    break;
                }
            }
            MyArray[j] = temp;
            m += 2;
        }
    }
}

void InsertSort(int n) {
    for (int i = 1; i < n; i++) {
        int key = MyArray[i];
        int j = i - 1;
        while (j >= 0 && MyArray[j] > key) {
            c++;
            MyArray[j + 1] = MyArray[j];
            j--;
            m++;
        }
        if (j >= 0) c++;
        MyArray[j + 1] = key;
        m++;
    }
}

void TestSorting(int n) {
    printf("\n==== Массив по возрастанию ====");
    FillInc(n);
    printf("\nНачальный массив: ");
    PrintArray(n);
    printf("\nКонтрольная сумма: %d", CheckSum(n));
    ShellSort(n);
    printf("\nОтсортированный массив: ");
    PrintArray(n);
    printf("\nОтсортированная сумма: %d", CheckSum(n));
    Reset();
    
    printf("\n==== Массив по убыванию ====");
    FillDec(n);
    printf("\nНачальный массив: ");
    PrintArray(n);
    printf("\nКонтрольная сумма: %d", CheckSum(n));
    ShellSort(n);
    printf("\nОтсортированный массив: ");
    PrintArray(n);
    printf("\nОтсортированная сумма: %d", CheckSum(n));
    Reset();
    
    printf("\n==== Случайный массив ====");
    FillRand(n);
    printf("\nНачальный массив: ");
    PrintArray(n);
    printf("\nКонтрольная сумма: %d", CheckSum(n));
    ShellSort(n);
    printf("\nОтсортированный массив: ");
    PrintArray(n);
    printf("\nОтсортированная сумма: %d", CheckSum(n));
    Reset();
}

int main() {
    srand(time(NULL));
    TestSorting(10);
    return 0;
}