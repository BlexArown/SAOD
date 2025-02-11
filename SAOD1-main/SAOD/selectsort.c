#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Функция для обмена элементов
void swap(int *a, int *b, int *swapCount) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*swapCount)++;
}

// Обычная сортировка методом прямого выбора
void selectSort(int arr[], int n, int *compCount, int *swapCount) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            (*compCount)++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(&arr[i], &arr[minIdx], swapCount);
        }
    }
}

// Оптимизированная сортировка (исключение фиктивных перестановок)
void optimizedSelectSort(int arr[], int n, int *compCount, int *swapCount) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            (*compCount)++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(&arr[i], &arr[minIdx], swapCount);
        }
    }
}

// Вывод массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Подсчет контрольной суммы
int CheckSum(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	sum += arr[i];
	return sum;
}
int RunNumber(int arr[], int n){
	int runs = 1;
	for (int i = 1; i < n; i++){
		if (arr[i] < arr[i-1]) runs++;
	}
	return runs;
}
// Генерация случайного массива
void generateArray(int arr[], int n, int type) {
    if (type == 0) { // Случайный массив
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }
    } else if (type == 1) { // Отсортированный по возрастанию
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
    } else { // Отсортированный по убыванию
        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
    }
}

// Тестирование сортировки на разных типах массивов
void testSorting(int n) {
    int arr[n];
    int compCount = 0, swapCount = 0;

    // Тест на случайном массиве
    generateArray(arr, n, 0);
    printf("Исходный случайный массив: ");
    printArray(arr, n);
    selectSort(arr, n, &compCount, &swapCount);
    printf("Отсортированный массив: ");
    printArray(arr, n);
    printf("Сравнения: %d, Перестановки: %d\n\n", compCount, swapCount);

    // Тест на отсортированном массиве
    compCount = swapCount = 0;
    generateArray(arr, n, 1);
    printf("Исходный возрастающий массив: ");
    printArray(arr, n);
    selectSort(arr, n, &compCount, &swapCount);
    printf("Отсортированный массив: ");
    printArray(arr, n);
    printf("Сравнения: %d, Перестановки: %d\n\n", compCount, swapCount);

    // Тест на убывающем массиве
    compCount = swapCount = 0;
    generateArray(arr, n, 2);
    printf("Исходный убывающий массив: ");
    printArray(arr, n);
    selectSort(arr, n, &compCount, &swapCount);
    printf("Отсортированный массив: ");
    printArray(arr, n);
    printf("Сравнения: %d, Перестановки: %d\n\n", compCount, swapCount);
}

// Сортировка первых 8 символов ФИО
void sortFIO() {
    char fio[] = "Пастухов"; // Пример ФИО (первые 8 букв)
    int n = strlen(fio);

    printf("Исходные 8 символов ФИО: %s\n", fio);
    // Алгоритм SelectSort для символов
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (fio[j] < fio[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            char temp = fio[i];
            fio[i] = fio[minIdx];
            fio[minIdx] = temp;
        }
    }
    printf("Отсортированные символы ФИО: %s\n\n", fio);
}

int main() {
    srand(time(0));

    printf("=== Сортировка ФИО ===\n");
    sortFIO();

    printf("=== Исследование сортировки ===\n");
    testSorting(10);

    return 0;
}

