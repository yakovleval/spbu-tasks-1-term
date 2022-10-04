#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "person.h"

//#define TESTS_NUMBER 3

bool testAddPerson() {
//    const int testsNumber = 3;
    Person *list = NULL;
    const char *names[] = {"testname", "testname2", "testname3"};
    const char *numbers[] = {"+79000000000", "1234", "239"};
    for (int i = 0; i < sizeof(names) / sizeof(char*); i++) {
        addPerson(&list, names[i], numbers[i]);
    }
    bool result = true;
    int i = 0;
    for (Person **iterator = &list; *iterator != NULL; iterator = &(*iterator)->next, i++) {
        result &= strcmp((*iterator)->name, names[i]) == 0;
        result &= strcmp((*iterator)->number, numbers[i]) == 0;
    }
    return result;
}

bool testFindByNumber() {
//    const int testsNumber = 3;
    Person *list = NULL;
    const char *names[] = {"testname", "testname2", "testname3"};
    const char *numbers[] = {"+79000000000", "1234", "239"};
    for (int i = 0; i < sizeof(names) / sizeof(char*); i++) {
        addPerson(&list, names[i], numbers[i]);
    }
    bool result = true;
    for (int i = 0; i < sizeof(names) / sizeof(char*); i++) {
        Person *node = findByNumber(&list, numbers[i]);
        result &= strcmp(node->number, numbers[i]) == 0;
    }
    return result;
}

bool testFindByName() {
//    const int testsNumber = 3;
    Person *list = NULL;
    const char *names[] = {"testname", "testname2", "testname3"};
    const char *numbers[] = {"+79000000000", "1234", "239"};
    for (int i = 0; i < sizeof(names) / sizeof(char*); i++) {
        addPerson(&list, names[i], numbers[i]);
    }
    bool result = true;
    for (int i = 0; i < sizeof(names) / sizeof(char*); i++) {
        Person *node = findByName(&list, names[i]);
        result &= strcmp(node->name, names[i]) == 0;
    }
    return result;
}

bool isPassed() {
    return testAddPerson() &&
           testFindByName() &&
           testFindByNumber();
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    printf("тесты пройдены\n");
//    const int bufSize = 101;
    Person *list = NULL;
    char name[MAX_SIZE] = {0};
    char number[MAX_SIZE] = {0};
    loadList(&list);
    while (true) {
        printf("введите номер действия:\n");
        int action = 0;
        Person *node = NULL;
        scanf(" %d", &action);
        switch (action) {
            case 0:
                freeList(list);
                return 0;
            case 1:
                printf("введите имя и номер:\n");
                scanf(" %[^\n]", name);
                scanf(" %[^\n]", number);
                addPerson(&list, name, number);
                break;
            case 2:
                printList(&list);
                break;
            case 3:
                printf("введите имя:\n");
                scanf(" %[^\n]", name);
                node = findByName(&list, name);
                if (node == NULL) {
                    printf("номер не найден\n");
                } else {
                    printf("номер: %s\n", node->number);
                }
                break;
            case 4:
                printf("введите номер:\n");
                scanf(" %[^\n]", number);
                node = findByNumber(&list, number);
                if (node == NULL) {
                    printf("имя не найдено\n");
                } else {
                    printf("имя: %s\n", node->name);
                }
                break;
            case 5:
                saveList(&list);
                printf("данные сохранены\n");
                break;
            default:
                printf("неизвестная команда\n");
        }
    }
}