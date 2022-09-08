#include <stdio.h>
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
    printf("введите через пробел элементы массива (целые числа, -1 -- конец массива)\n");
    int array[MAX_LENGTH] = {0};
    int i = 0;
    int read = 0;
    do {
        scanf("%d", &read);
        array[i] = read;
        i++;
    } while (read != -1);
    printf("количество нулей в массиве равно %d\n", zerosNumber(array));
    return 0;
}
