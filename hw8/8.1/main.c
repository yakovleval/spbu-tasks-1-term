#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "tree.h"
#include "tests.h"
#define MAX_BUFFER 256

int main() {
    setlocale(LC_ALL, "RU-ru");

    if (!isPassed()) {
        return 0;
    }

    printf("0 -- выход\n");
    printf("1 -- добавить/заменить значение по ключу\n");
    printf("2 -- найти значение по ключу\n");
    printf("3 -- проверить наличие ключа\n");
    printf("4 -- удалить значение по ключу\n");
    Node *root = NULL;
    char key[MAX_BUFFER] = {0};
    char value[MAX_BUFFER] = {0};
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
                scanf("%255s", key);
                scanf("%255s", value);
                root = addNode(root, key, value);
                break;
            case 2:
                printf("введите ключ: \n");
                scanf("%255s", key);
                char *foundValue = findValue(root, key);
                if (foundValue == NULL) {
                    printf("не найдено\n");
                } else {
                    printf("%s\n", foundValue);
                }
                break;
            case 3:
                printf("введите ключ: \n");
                scanf("%255s", key);
                if (findNode(root, key) == NULL) {
                    printf("не найдено\n");
                } else {
                    printf("ключ есть\n");
                }
                break;
            case 4:
                printf("введите ключ: \n");
                scanf("%255s", key);
                root = deleteNode(root, key);
                break;
            default:
                printf("неизвестная команда\n");
                break;
        }
    }
    return 0;
}
