#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "mergesort.h"

bool cmpLists(Person *left, Person *right) {
    while (left != NULL && right != NULL) {
        if (strcmp(left->name, right->name) != 0 ||
        strcmp(left->number, right->number) != 0) {
            return false;
        }
        left = left->next;
        right = right->next;
    }
    if (left != NULL && right != NULL) {
        return false;
    }
    return true;
}

bool testOneElement() {
    bool result = true;
    Person person = {"a", "1", NULL};
    Person *list = &person;
    Person expected[] = {{"a", "1", NULL}};
    mergeSort(&list, NAME);
    result &= cmpLists(list, expected);
    mergeSort(&list, NUMBER);
    result &= cmpLists(list, expected);
    return result;
}

bool testList() {
    Person list[] = {{"b", "2", &list[1]}, {"a", "3", &list[2]}, {"c", "1", NULL}};
    Person expectedByName[] = {{"a", "3", &list[1]}, {"b", "2", &list[2]}, {"c", "1", NULL}};
    Person expectedByNumber[] = {{"c", "1", &list[1]}, {"b", "2", &list[2]}, {"a", "3", NULL}};
    Person *sourceList = &list[0];
    Person *listExpByName = &expectedByName[0];
    Person *listExpByNumber = &expectedByNumber[0];
    bool result = true;
    mergeSort(&sourceList, NAME);
    result &= cmpLists(listExpByName, expectedByName);
    mergeSort(&sourceList, NUMBER);
    result &= cmpLists(listExpByNumber, expectedByNumber);
    return result;
}

bool isPassed() {
    return  testOneElement() &&
            testList();
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    Person *list = NULL;
    loadList(&list, "data.txt");
    printf("введите способ сортировки (0 - по имени, 1 - по номеру):\n");
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
        case 0:
            mergeSort(&list, NAME);
            break;
        case 1:
            mergeSort(&list, NUMBER);
            break;
        default:
            printf("неизвестная команда\n");
            return 0;
    }
    printf("отсортированный список:\n");
    printList(&list);
    return 0;
}
