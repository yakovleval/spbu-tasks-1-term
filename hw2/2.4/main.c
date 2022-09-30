#include <stdbool.h>
#include <locale.h>

void swap(int *left, int *right) {
    const int tmp = *left;
    *left = *right;
    *right = tmp;
}

void partition(int *array, const int size, const int pivot) {
    int leftIndex = 0;
    int rightIndex = size - 1;
    while (leftIndex <= rightIndex) {
        while (leftIndex < size && array[leftIndex] < pivot) {
            leftIndex++;
        }
        while (rightIndex >= 0 && array[rightIndex] >= pivot) {
            rightIndex--;
        }
        if (leftIndex <= rightIndex) {
            swap(&array[leftIndex], &array[rightIndex]);
            leftIndex++;
            rightIndex--;
        }
    }
}

bool isParted(const int *array, const int size, const int pivot) {
    int index = 0;
    while (array[index] < pivot) {
        index++;
    }
    while (index < size && array[index] >= pivot) {
        index++;
    }
    return index == size;
}

bool testPartition(const int *array, const int size, const int pivot) {
    int *testArray = (int *) calloc(size, sizeof(int));
    if (!testArray) {
        return false;
    }
    memcpy(testArray, array, size * sizeof(int));
    partition(testArray, size, pivot);
    const bool result = isParted(testArray, size, pivot);
    free(testArray);
    return result;
}

bool isPassed() {
    const int testArraysNumber = 5;
    const int testArraysSize = 5;
    const int testArrays[6][5] =
            {
                    {5, 4, 3, 2, 1},
                    {5, 3, 3, 3, 1},
                    {3, 3, 3, 3, 3},
                    {5, 4, 3, 2, 1},
                    {5, 4, 3, 2, 1},
                    {2, 1, 3, 5, 4}
            };
    const int pivots[6] = {3, 3, 3, 5, 1, 3};
    bool result = true;
    for (int i = 0; i < testArraysNumber; i++) {
        result &= testPartition(testArrays[i], testArraysSize, pivots[i]);
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    printf("тесты пройдены\n");

    int size = 0;
    do {
        printf("введите размер массива (целое неотрицательное число): \n");
        scanf("%d", &size);
    } while (size < 0);

    int *array = (int *) calloc(size, sizeof(int));
    if (!array) {
        printf("ошибка выделения памяти\n");
        return 0;
    }
    srand(239);
    printf("исходный массив: \n");
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\n");
    const int pivot = array[0];
    partition(array, size, pivot);
    printf("массив после разделения по числу %d: \n", pivot);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
