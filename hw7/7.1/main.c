#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

#define MAX_BUFFER 256

bool testAddAndFind() {
    Node *root = NULL;
    addNode(&root, 555, "string1");
    addNode(&root, 666, "string 2");
    const bool result = strcmp(findValue(root, 555), "string1") == 0 &&
                        strcmp(findValue(root, 666), "string 2") == 0 &&
                        findValue(root, 777) == NULL;
    freeTree(root);
    return result;
}

bool testChange() {
    Node *root = NULL;
    addNode(&root, 555, "string1");
    addNode(&root, 666, "string2");
    addNode(&root, 555, "string");
    const bool result = strcmp(findValue(root, 555), "string") == 0 &&
                        strcmp(findValue(root, 666), "string2") == 0;
    freeTree(root);
    return result;
}

bool testDel() {
    Node *root = NULL;
    addNode(&root, 555, "string1");
    addNode(&root, 666, "string2");
    deleteNode(&root, 555);
    const bool result = findValue(root, 555) == NULL &&
                        strcmp(findValue(root, 666), "string2") == 0;
    freeTree(root);
    return result;
}

bool isPassed() {
    return testAddAndFind() &&
           testChange() &&
           testDel();
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("Тесты не пройдены\n");
        return 0;
    }

    printf("0 -- выход\n");
    printf("1 -- добавить/заменить значение по ключу\n");
    printf("2 -- найти значение по ключу\n");
    printf("3 -- проверить наличие ключа\n");
    printf("4 -- удалить значение по ключу\n");
    Node *root = NULL;
    int key = 0;
    char buffer[MAX_BUFFER] = {0};
    while (true) {
        printf("Введите номер действия: \n");
        int action = 0;
        scanf(" %d", &action);
        switch (action) {
            case 0:
                freeTree(root);
                return 0;
            case 1:
                printf("введите ключ и значение: \n");
                scanf("%d", &key);
                scanf("%s", buffer);
                Error error = addNode(&root, key, buffer);
                if (error != 0) {
                    printf("ошибка добавления в словарь\n");
                    freeTree(root);
                    return 0;
                }
                break;
            case 2:
                printf("введите ключ: \n");
                scanf("%d", &key);
                char *foundValue = findValue(root, key);
                if (foundValue == NULL) {
                    printf("не найдено\n");
                } else {
                    printf("%s\n", foundValue);
                }
                break;
            case 3:
                printf("введите ключ: \n");
                scanf("%d", &key);
                if (*findNode(&root, key) == NULL) {
                    printf("не найдено\n");
                } else {
                    printf("ключ есть\n");
                }
                break;
            case 4:
                printf("введите ключ: \n");
                scanf("%d", &key);
                deleteNode(&root, key);
                break;
            default:
                printf("неизвестная команда\n");
                break;
        }
    }
}
