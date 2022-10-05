#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <memory.h>
#include <stdlib.h>

#define TEST_ARRAYS_NUMBER 10
#define ARRAYS_SIZE 10

void insertionSort(int *array, const int leftBound, const int rightBound) {
    for (int i = leftBound + 1; i <= rightBound; i++) {
        for (int j = i - 1; j >= leftBound && array[j] > array[j + 1]; j--) {
            const int tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
        }
    }
}

void insertionEvenSort(int *array, const int leftBound, const int rightBound) {
    for (int i = leftBound + 1; i <= rightBound; i++) {
        if (array[i] % 2 == 1) {
            continue;
        }
        int nextEven = i;
        for (int j = i - 1; j >= leftBound; j--) {
            if (array[j] % 2 == 1 || array[j] <= array[nextEven]) {
                continue;
            }
            const int tmp = array[j];
            array[j] = array[nextEven];
            array[nextEven] = tmp;
            nextEven = j;
        }
    }
}

void generateRandomEvenArray(int *array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % size;
        array[i] = array[i] % 2 == 1 ? array[i] + 1 : array[i];
    }
}

bool isEqual(const int* left, const int *right, const int size) {
    for (int i = 0; i < size; i++) {
        if (left[i] != right[i]) {
            return false;
        }
    }
    return true;
}

bool testEvenSort(int *array, const int size) {
    int *sortedArray = calloc(size, sizeof(int));
    memcpy(sortedArray, array, size * sizeof(int));
    insertionSort(sortedArray, 0, size - 1);
    insertionEvenSort(array, 0, size - 1);
    bool result = isEqual(sortedArray, array, size);
    free(sortedArray);
    return result;
}

bool testRandomArrays() {
    int *testArrays[TEST_ARRAYS_NUMBER] = {NULL};
    for (int i = 0; i < TEST_ARRAYS_NUMBER; i++) {
        testArrays[i] = calloc(ARRAYS_SIZE, sizeof(int));
        generateRandomEvenArray(testArrays[i], ARRAYS_SIZE);
    }

    bool result = true;
    for (int i = 0; i < TEST_ARRAYS_NUMBER; i++) {
        result &= testEvenSort(testArrays[i], ARRAYS_SIZE);
    }
    for (int i = 0; i < TEST_ARRAYS_NUMBER; i++) {
        free(testArrays[i]);
    }
    return result;
}

bool isPassed() {
    return testRandomArrays();
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    printf("введите размер массива:\n");
    int size = 0;
    scanf("%d", &size);
    if (size <= 0) {
        return 0;
    }
    printf("введите элементы массива через пробел\n");
    int *array = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    insertionEvenSort(array, 0, size - 1);

    printf("отсортированный массив\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
