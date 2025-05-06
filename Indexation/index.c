#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

typedef struct {
    char name[50];
    char phone[20];
    char address[100];
    char email[50];
} PBook;


int lessPhonethenName(PBook x, PBook y) {
    int phoneCompare = strcmp(x.phone, y.phone);
    if (phoneCompare < 0) return 1;
    else if (phoneCompare > 0) return 0;
    else return (strcmp(x.name, y.name) < 0);
}

int lessNamethenPhone(PBook x, PBook y) {
    int nameCompare = strcmp(x.name, y.name);
    if (nameCompare < 0) return 1;
    else if (nameCompare > 0) return 0;
    else return (strcmp(x.phone, y.phone) < 0);
}

void createIndexArray(PBook phoneBook[], int index[], int n, int (*less)(PBook, PBook)) {
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (less(phoneBook[index[j]], phoneBook[index[minIndex]])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = index[i];
            index[i] = index[minIndex];
            index[minIndex] = temp;
        }
    }
}

void printPhoneBookByIndex(PBook phoneBook[], int index[], int n) {
    printf("%-25s %-20s %-35s %-30s\n", "Имя", "Телефон", "Адрес", "Почта");
    printf("---------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        int idx = index[i];
        printf("%-20s %-15s %-30s %-30s\n",
               phoneBook[idx].name,
               phoneBook[idx].phone,
               phoneBook[idx].address,
               phoneBook[idx].email);
    }
    printf("\n");
}

int main() {
    PBook phoneBook[MAX_RECORDS] = {
        {"Alex", "56890", "456 Oak St", "alex@google.com"},
        {"Alex", "32459", "101 Elm St", "bonny@google.com"},
        {"Danny", "87777", "101 Elm St", "danny@google.com"},
        {"Fade", "32459", "789 Pine St", "fade@google.com"},
        {"Barry", "32514", "123 Main St", "barry@google.com"},
    };

    int nameIndex[MAX_RECORDS];
    int phoneIndex[MAX_RECORDS];

    printf("Исходный телефонный справочник:\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%-20s %-15s %-30s %-30s\n",
               phoneBook[i].name,
               phoneBook[i].phone,
               phoneBook[i].address,
               phoneBook[i].email);
    }
    printf("\nИндексы до сортировок:\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
    printf("%d ", i);
    }
    printf("\n\n");
    createIndexArray(phoneBook, nameIndex, MAX_RECORDS, lessNamethenPhone);
    createIndexArray(phoneBook, phoneIndex, MAX_RECORDS, lessPhonethenName);

    printf("Индексы после сортировки по имени:\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
    printf("%d ", nameIndex[i]);
    }
    printf("\n\n");

    printf("Индексы после сортировки по телефону:\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
    printf("%d ", phoneIndex[i]);
    }
    printf("\n\n");

    printf("Сортировка по имени (с использованием индексного массива):\n");
    printPhoneBookByIndex(phoneBook, nameIndex, MAX_RECORDS);

    printf("Сортировка по телефону (с использованием индексного массива):\n");
    printPhoneBookByIndex(phoneBook, phoneIndex, MAX_RECORDS);
    return 0;
}
