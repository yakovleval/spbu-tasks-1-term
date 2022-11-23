#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "stack.h"

int main() {
    setlocale(LC_ALL, "RU-ru");
    Node *stack = NULL;
    while (true) {
        printf("введите команду:\n");
        char buffer[10];
        scanf("%9s", buffer);
        if (strcmp(buffer, "exit") == 0) {
            deleteAll(&stack);
            return 0;
        }
        if (strcmp(buffer, "push") == 0) {
            int number = 0;
            scanf("%d", &number);
            push(&stack, number);
        }
        if (strcmp(buffer, "pop") == 0) {
            int value = 0;
            if (pop(&stack, &value) != 0) {
                printf("в стеке недостаточно элементов\n");
            }
            else
                printf("%d\n", value);
        }
        if (strcmp(buffer, "add") == 0) {
            if (stack == NULL || stack->next == NULL) {
                printf("в стеке недостаточно элементов\n");
            }
            else {
                int left = 0, right = 0;
                pop(&stack, &left);
                pop(&stack, &right);
                push(&stack, left + right);
            }
        }
        if (strcmp(buffer, "print") == 0) {
            print(stack);
            printf("\n");
        }
        else
            printf("неизвестная команда\n");
    }
}
