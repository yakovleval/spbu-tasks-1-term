#include <stdio.h>
#include <locale.h>

#define MAX_LENGTH 256

int zerosNumber(const int *array) {
    int count = 0;
    for (int i = 0; array[i] != -1; i++) {
        if (array[i] == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    printf("введите через пробел элементы массива (целые числа, -1 -- конец массива)\n");
    int read = 0;
    int count = 0;
    do {
        scanf("%d", &read);
        if (read == 0) {
            count++;
        }
    } while (read != -1);
    printf("количество нулей в массиве равно %d\n", count);
    return 0;
}
