#include <stdio.h>
#include <locale.h>
#include <malloc.h>

void shellSort(int *array, const int size) {
    for (int step = size / 2; step > 0; step /= 2) {
        for (int i = step; i < size; ++i) {
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step) {
                int tmp = array[j];
                array[j] = array[j + step];
                array[j + step] = tmp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    printf("введите размер массива:\n");
    int size = 0;
    scanf("%d", &size);
    if (size <= 0) {
        return 0;
    }
    printf("введите элементы массива через пробел:\n");
    int *array = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    shellSort(array, size);
    printf("отсортированный массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
