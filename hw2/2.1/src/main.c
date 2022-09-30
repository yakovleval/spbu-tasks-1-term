#include <stdio.h>
#include "solution.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RU-ru");
    for (int i = -10; i < 45; i++) {
        printf("номер числа Фибоначчи: %d\n", i);
        printf("итеративно: %d\n", iterativeFibonacci(i));
        printf("рекурсивно: %d\n", recursiveFibonacci(i));
    }
    return 0;
}
