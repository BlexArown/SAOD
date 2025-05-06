#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct tData
{
    struct tData *next;
    int data;
} tData;

// 1. Разработать функции для создания стека:
void AddToStack(tData** head, int data)
{
    tData* p = (tData*)malloc(sizeof(tData));
    p->data = data;
    p->next = *head;
    *head = p;
}

// - возр. стек;
void fillIncStack(tData **head, int n)
{
    for (int i = 1; i <= n; i++)
    {
        AddToStack(head, i);
    }
}

// - убыв. стек;
void fillDecStack(tData** head, int n)
{
    for (int i = n; i >= 1; i--)
    {
        AddToStack(head, i);
    }
}

// - случ. стек;
void fillRanStack(tData** head, int n)
{
    srand(time(NULL));
    for (int i = 1; i <= n; i++)
    {
        int ranNum = rand() % 100;
        AddToStack(head, ranNum);
    }
}

// 2. Разработать функции для создания очереди:
void AddToQueue(tData** head, tData** tail, int data)
{
    tData *p = (tData *)malloc(sizeof(tData));
    p->data = data;
    p->next = NULL;

    if (*tail == NULL)
    {
        *head = *tail = p;
    }
    else
    {
        (*tail)->next = p;
        *tail = p;
    }
}

// - возр. очередь;
void fillIncQueue(tData** head, tData** tail, int n)
{
    for (int i = 1; i <= n; i++)
    {
        AddToQueue(head, tail, i);
    }
}

// - убыв. очередь;
void fillDecQueue(tData** head, tData** tail, int n)
{
    for (int i = n; i >= 1; i--)
    {
        AddToQueue(head, tail, i);
    }
}

// - случ. очередь;
void fillRanQueue(tData** head, tData** tail, int n)
{
    srand(time(NULL));
    for (int i = 1; i <= n; i++)
    {
        int ranNum = rand() % 100;
        AddToQueue(head, tail, ranNum);
    }
}
// - удаление из стека
void delStackElement(tData** head)
{
    if (head != NULL)
    {
        tData *p = *head;
        *head = p->next;
        free(p);
    }
}

// - вывод элементов списка;
void print_list(tData *head)
{
    tData *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// - КСум списка;
int checksum(tData *head)
{
    int sum = 0;
    tData *p = head;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

// - Ксер списка
int count_series(tData *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int count = 1;
    tData *p = head;

    while (p->next != NULL)
    {
        if (p->data > p->next->data)
        {
            count++;
        }
        p = p->next;
    }
    return count;
}

void clear(tData *head)
{
    tData *p = head;
    while (p != NULL)
    {
        tData *temp_p = p;
        p=p->next;
        free(temp_p);
    }
}

void printForwardRecursive(tData *head)
{
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    printForwardRecursive(head->next);
}

void printBackwardRecursive(tData *head)
{
    if (head == NULL) {
        return;
    }
    printBackwardRecursive(head->next);
    printf("%d ", head->data);
}

typedef struct {
    tData *head;
    tData *tail;
} tQueue;

// - Инициализация очереди
void InitializeQueue(tQueue *q) {
    q->head = q->tail = NULL;
}

void MergeSeries(tData **a, int q, tData **b, int r, tQueue *c, int *cmp, int *move) {
    while (q > 0 && r > 0 && *a != NULL && *b != NULL) {
        (*cmp)++;
        if ((*a)->data <= (*b)->data) {
            if (c->head == NULL) {
                c->head = c->tail = *a;
            } else {
                c->tail->next = *a;
                c->tail = *a;
            }
            *a = (*a)->next;
            q--;
        } else {
            if (c->head == NULL) {
                c->head = c->tail = *b;
            } else {
                c->tail->next = *b;
                c->tail = *b;
            }
            *b = (*b)->next;
            r--;
        }
        (*move)++;
    }

    while (q > 0 && *a != NULL) {
        if (c->head == NULL) {
            c->head = c->tail = *a;
        } else {
            c->tail->next = *a;
            c->tail = *a;
        }
        *a = (*a)->next;
        q--;
        (*move)++;
    }

    while (r > 0 && *b != NULL) {
        if (c->head == NULL) {
            c->head = c->tail = *b;
        } else {
            c->tail->next = *b;
            c->tail = *b;
        }
        *b = (*b)->next;
        r--;
        (*move)++;
    }

    if (c->tail != NULL) {
        c->tail->next = NULL;
    }
}


void SplitLists(tData *head, tData **a, tData **b, int *n, int *move) {
    *a = head;
    *b = head->next;

    tData *k = *a, *p = *b;
    (*move)++;
    *n = 1; // Кол-во элементов

    while (p != NULL) {
        (*n)++;
        k->next = p->next;
        k = p;
        p = p->next;
        (*move)++;
    }
}

void MergeSort(tData **S, int *comparisons, int *moves) {
    // Пустой список или из одного элемента
    if (*S == NULL || (*S)->next == NULL) {
        return;
    }

    tQueue c[2];
    tData *a, *b;
    int n;
    SplitLists(*S, &a, &b, &n, moves);

    for (int p = 1; p < n; p *= 2) {
        InitializeQueue(&c[0]);
        InitializeQueue(&c[1]);
        int i = 0, m = n;

        while (m > 0) {
            int q = (m >= p) ? p : m;
            m -= q;

            int r = (m >= p) ? p : m;
            m -= r;

            MergeSeries(&a, q, &b, r, &c[i], comparisons, moves);

            i = 1 - i;
        }

        a = c[0].head;
        b = c[1].head;
    }

    if (c[0].tail != NULL) {
        c[0].tail->next = NULL;
    }
    *S = c[0].head;
}

int main() {
    int n = 20;
    int m = 0;
    tData *stack = NULL, *a = NULL, *b = NULL;

    printf("Создание случ. списка (20эл):\n");
    fillRanStack(&stack, n);
    printf("Исход. список:\n");
    print_list(stack);
    printf("КCум: %d, КСер: %d\n\n", checksum(stack), count_series(stack));

    int moves = 0;
    printf("Делим на два подсписка:\n");
    SplitLists(stack, &a, &b, &m, &moves);

    printf("A:\n");
    print_list(a);
    printf("КСум: %d, КСер: %d\n", checksum(a), count_series(a));

    printf("B:\n");
    print_list(b);
    printf("КСум: %d, КСер: %d\n\n", checksum(b), count_series(b));

    printf("Сливаем списки:\n");
    int i = 0;
    tQueue c[2];
    InitializeQueue(&c[0]);
    InitializeQueue(&c[1]);
    int Cfact = 0, Mfact = 0;
    int Ctheor = 0, Mtheor = 0;

    printf("Перед слиянием:\n");
    printf("m = %d\n", m);
    printf("Список A:\n");
    print_list(a);
    printf("Список B:\n");
    print_list(b);

    while (m > 0) {
        int q = (m >= 1) ? 1 : m;
        m -= q;
        int r = (m >= 1) ? 1 : m;
        m -= r;

        Ctheor += ((q < r ? q : r) + q + r - 1) / 2;
        Mtheor += q + r;

        MergeSeries(&a, q, &b, r, &c[i], &Cfact, &Mfact);
        i = 1 - i;
    }

    printf("\nОчередь C[0]:\n");
    print_list(c[0].head);
    printf("КСум: %d, КСер: %d\n", checksum(c[0].head), count_series(c[0].head));

    printf("Очередь C[1]:\n");
    print_list(c[1].head);
    printf("КСум: %d, КСер: %d\n", checksum(c[1].head), count_series(c[1].head));

    printf("Сложность слияния списков:\nТеор: C = %d, M = %d\nФакт: C = %d, M = %d\n\n", Ctheor, Mtheor, Cfact, Mfact);

    // Сортировка
    clear(stack);
    stack = NULL;

    printf("Сортировка слиянием:\n");
    fillRanStack(&stack, n);

    printf("Исход. случ. список:\n");
    print_list(stack);
    printf("КСум: %d, КСер: %d\n", checksum(stack), count_series(stack));
    printf("\n");

    Cfact = 0;
    Mfact = 0;
    MergeSort(&stack, &Cfact, &Mfact);

    printf("Отсор. список:\n");
    print_list(stack);
    printf("КСум: %d, КСер: %d\n", checksum(stack), count_series(stack));

    Ctheor = (int)(log2(n) * n);
    Mtheor = (int)(log2(n) * n);

    printf("Сложность сортировки:\nТеор: C = %d, M = %d\nФакт: C = %d, M = %d\n\n", Ctheor, Mtheor, Cfact, Mfact);
    printf("|       |               |            |           |               |\n");
    printf("|   N   |     M + C     |    Убыв.   |   Случ.   |    Возраст.   |\n");
    printf("|       |     теор      |            |           |               |\n");

    for (int j = 100; j <= 500; j += 100) {
        int Ttheor = (int)(2 * log2(j) * j);

        clear(stack);
        stack = NULL;
        Cfact = 0;
        Mfact = 0;
        fillRanStack(&stack, j);
        MergeSort(&stack, &Cfact, &Mfact);
        int Trand = Cfact + Mfact;

        clear(stack);
        stack = NULL;
        Cfact = 0;
        Mfact = 0;
        fillIncStack(&stack, j);
        MergeSort(&stack, &Cfact, &Mfact);
        int Tinc = Cfact + Mfact;

        clear(stack);
        stack = NULL;
        Cfact = 0;
        Mfact = 0;
        fillDecStack(&stack, j);
        MergeSort(&stack, &Cfact, &Mfact);
        int Tdec = Cfact + Mfact;

        printf(" %5d  %13d  %10d  %9d  %13d \n", j, Ttheor, Tdec, Trand, Tinc);
    }
}
