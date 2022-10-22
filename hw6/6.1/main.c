#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "list.h"

int main() {
    setlocale(LC_ALL, "RU-ru");
    List *list = NULL;
    while (true) {
        printf("введите команду:\n");
        int command = 0;
        scanf("%d", &command);
        Value value;
        switch (command) {
            case 0:
                freeList(list);
                return 0;
            case 1:
                printf("введите значение:\n");
                scanf("%d", &value);
                addValue(&list, value);
                break;
            case 2:
                printf("введите значение:\n");
                scanf("%d", &value);
                deleteValue(&list, value);
                break;
            case 3:
                printList(list);
                break;
        }
    }
    return 0;
}
