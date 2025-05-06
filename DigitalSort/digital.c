#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tData {
    struct tData *next;
    union {
        int Data;
        unsigned char digit[sizeof(int)];
    } data;
} tData;

typedef struct {
    tData *head;
    tData *tail;
} tQueue;

int M = 0; // Счётчик перемещений

void AddToQueue(tData **head, tData **tail, int data) {
    tData *p = (tData *)malloc(sizeof(tData));
    p->data.Data = data;
    p->next = NULL;
    if (*tail == NULL) {
        *head = *tail = p;
    } else {
        (*tail)->next = p;
        *tail = p;
    }
}

void fillDecQueue(tData **head, tData **tail, int n) {
    for (int i = n; i >= 1; i--) {
        AddToQueue(head, tail, i);
    }
}

void fillRanQueue(tData **head, tData **tail, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int ranNum = rand() % 1000 + 1;
        AddToQueue(head, tail, ranNum);
    }
}

void fillIncQueue(tData **head, tData **tail, int n) {
    for (int i = 1; i <= n; i++) {
        AddToQueue(head, tail, i);
    }
}

void print_list(tData *head) {
    while (head != NULL) {
        printf("%d ", head->data.Data);
        head = head->next;
    }
    printf("\n");
}

void clear(tData *head) {
    while (head != NULL) {
        tData *temp = head;
        head = head->next;
        free(temp);
    }
}

int checksum(tData *head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data.Data;
        head = head->next;
    }
    return sum;
}

int count_series(tData *head) {
    if (!head) return 0;
    int count = 1;
    int prev = head->data.Data;
    tData *current = head->next;
    while (current) {
        if (current->data.Data < prev) count++;
        prev = current->data.Data;
        current = current->next;
    }
    return count;
}

tData* DigitalSort(tData *head, int bytes) {
    for (int bit = 0; bit < bytes * 8; bit++) {
        tData *zero_head = NULL, *zero_tail = NULL;
        tData *one_head = NULL, *one_tail = NULL;
        tData *current = head;

        while (current) {
            int digit = (current->data.Data >> bit) & 0x1;
            tData *next = current->next;
            current->next = NULL;

            if (digit == 0) {
                if (!zero_head) {
                    zero_head = zero_tail = current;
                } else {
                    zero_tail->next = current;
                    zero_tail = current;
                }
            } else {
                if (!one_head) {
                    one_head = one_tail = current;
                } else {
                    one_tail->next = current;
                    one_tail = current;
                }
            }

            current = next;
        }

        head = NULL;
        tData **tail = &head;

        if (zero_head) {
            *tail = zero_head;
            while (*tail) {
                tail = &((*tail)->next);
                M++;
            }
        }

        if (one_head) {
            *tail = one_head;
            while (*tail) {
                tail = &((*tail)->next);
                M++;
            }
        }
    }

    return head;
}

void testDigitalSort(int bytes) {
    int sizes[] = {100, 200, 300, 400, 500};
    printf("\nЦифровая сортировка на %d бит:\n", bytes * 8);
    printf("|       |             |         |         |         |\n");
    printf("|   N   |    Теор.    |  Убыв.  |  Случ.  |  Возр.  |\n");
    printf("|       |             |         |         |         |\n");

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int theory = bytes * 8 * n;
        int results[3] = {0};

        for (int t = 0; t < 3; t++) {
            tData *head = NULL, *tail = NULL;

            switch(t) {
                case 0: fillDecQueue(&head, &tail, n); break;
                case 1: fillRanQueue(&head, &tail, n); break;
                case 2: fillIncQueue(&head, &tail, n); break;
            }

            M = 0;
            head = DigitalSort(head, bytes);
            results[t] = M;
            clear(head);
        }
        printf(" %5d  %9d  %11d  %8d  %8d \n", n, theory, results[0], results[1], results[2]);
    }
}

void demoSort(int bytes, int n) {
    tData *head = NULL, *tail = NULL;
    fillRanQueue(&head, &tail, n);

    printf("\nСортировка (%d элем-ов):\n", n);
    printf("Исход. список:\n");
    print_list(head);

    int sum_before = checksum(head);
    int series_before = count_series(head);
    printf("КСум до сортировки: %d\n", sum_before);
    printf("КСер до сортировки: %d\n", series_before);

    M = 0;
    head = DigitalSort(head, bytes);

    printf("\nОтсорт. список (M=%d):\n", M);
    print_list(head);

    int sum_after = checksum(head);
    int series_after = count_series(head);
    printf("КСум после сортировки: %d\n", sum_after);
    printf("КСер после сортировки: %d\n", series_after);

    clear(head);
}
int main() {
    testDigitalSort(2);
    demoSort(2, 20);
    testDigitalSort(4);
    demoSort(4, 20);

    return 0;
}
