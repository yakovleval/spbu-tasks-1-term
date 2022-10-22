#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int findSurvivor(int solders, int step) {
    List **current = addNodes(solders);;
    while ((*current)->next != *current) {
        for (int i = 0; i < step - 1; i++) {
            current = &(*current)->next;
        }
        deleteNode(current);
    }
    int result = (*current)->value;
    free(*current);
    return result;
}

int expected(int solders, int step) {
    if (solders == 1) {
        return 1;
    }
    return 1 + (expected(solders - 1, step) + step - 1) % solders;
}

bool isPassed() {
    for (int n = 1; n < 11; n++) {
        for (int m = 1; m <= 11; m++) {
            if (findSurvivor(n, m) != expected(n, m)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    printf("введите числа n и m:\n");
    int solders = 0, step = 0;
    scanf("%d%d", &solders, &step);
    while (solders <= 0 || step <= 0) {
        printf("количество сикариев n и число m должны быть положительными\n");
        printf("введите числа n и m:\n");
        scanf("%d%d", &solders, &step);
    }
    printf("в живых останется воин под номером %d\n", findSurvivor(solders, step));
    return 0;
}
