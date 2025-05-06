#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 5

typedef struct
{
    char name[50];
    char phone[20];
    char address[100];
    char email[50];
} PBook;

int lessPhonethenName(PBook x, PBook y)
{
    int phoneCompare = strcmp(x.phone, y.phone);
    if (phoneCompare < 0)
        return 1;
    else if (phoneCompare > 0)
        return 0;
    else
        return (strcmp(x.name, y.name) < 0);
}

int lessNamethenPhone(PBook x, PBook y)
{
    int nameCompare = strcmp(x.name, y.name);
    if (nameCompare < 0)
        return 1;
    else if (nameCompare > 0)
        return 0;
    else
        return (strcmp(x.phone, y.phone) < 0);
}

int morePhonethenName(PBook x, PBook y)
{
    int phoneCompare = strcmp(x.phone, y.phone);
    if (phoneCompare < 0)
        return 0;
    else if (phoneCompare > 0)
        return 1;
    else
        return (strcmp(x.name, y.name) > 0);
}

int moreNamethenPhone(PBook x, PBook y)
{
    int nameCompare = strcmp(x.name, y.name);
    if (nameCompare < 0)
        return 0;
    else if (nameCompare > 0)
        return 1;
    else
        return (strcmp(x.phone, y.phone) > 0);
}

void selectionSort(PBook phoneBook[], int n, int (*sortBy)(PBook, PBook))
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (sortBy(phoneBook[j], phoneBook[minIndex]))
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            PBook temp = phoneBook[i];
            phoneBook[i] = phoneBook[minIndex];
            phoneBook[minIndex] = temp;
        }
    }
}

void printPhoneBook(PBook phoneBook[], int n)
{
    printf("%-22s %-25s %-35s %-30s\n", "Имя     |", "Телефон     |", "Адрес       |", "Почта         |");
    for (int i = 0; i < n; i++)
    {
        printf("%-20s %-15s %-30s %-30s\n", phoneBook[i].name, phoneBook[i].phone, phoneBook[i].address, phoneBook[i].email);
    }
    printf("\n");
}

int main()
{
    PBook phoneBook[MAX_RECORDS] = {
        {"Alex", "56890", "456 Oak St", "alex@google.com"},
        {"Alex", "32459", "101 Elm St", "bonny@google.com"},
        {"Danny", "87777", "101 Elm St", "danny@google.com"},
        {"Fade", "32459", "789 Pine St", "fade@google.com"},
        {"Barry", "32514", "123 Main St", "barry@google.com"},
    };

    printf("Исходный телефонный справочник:\n");
    printPhoneBook(phoneBook, MAX_RECORDS);

    selectionSort(phoneBook, MAX_RECORDS, lessPhonethenName);
    printf("\n\n\nОтсортированный телефонный справочник по номеру телефона по возрастанию:\n");
    printPhoneBook(phoneBook, MAX_RECORDS);

    selectionSort(phoneBook, MAX_RECORDS, lessNamethenPhone);
    printf("\n\n\nОтсортированный телефонный справочник по имени по возрастанию:\n");
    printPhoneBook(phoneBook, MAX_RECORDS);

    selectionSort(phoneBook, MAX_RECORDS, morePhonethenName);
    printf("\n\n\nОтсортированный телефонный справочник по номеру телефона по убыванию:\n");
    printPhoneBook(phoneBook, MAX_RECORDS);

    selectionSort(phoneBook, MAX_RECORDS, moreNamethenPhone);
    printf("\n\n\nОтсортированный телефонный справочник по имени по убыванию:\n");
    printPhoneBook(phoneBook, MAX_RECORDS);

    return 0;
}
