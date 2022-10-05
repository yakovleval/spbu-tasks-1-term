#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

#define TEST_ARRAYS_NUMBER 10
#define ARRAYS_SIZE 10

void insertionEvenSort(int *array, const int leftBound, const int rightBound) {
    for (int i = leftBound + 1; i <= rightBound; i++) {
        if (array[i] % 2 == 1) {
            continue;
        }
        int nextEven = i;
        for (int j = i - 1; j >= leftBound; j--) {
            if (array[j] % 2 == 1 || array[j] <= array[i]) {
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
        array[i] = rand();
        array[i] = array[i] % 2 == 1 ? array[i] + 1 : array[i];
    }
}

bool testRandomArrays() {
    int *testArrays[TEST_ARRAYS_NUMBER] = {NULL};
    for (int i = 0; i < TEST_ARRAYS_NUMBER; i++) {
        testArrays[i] = calloc(ARRAYS_SIZE, sizeof(int));
        generateRandomEvenArray(testArrays[i], ARRAYS_SIZE);
    }

    bool result = true;
    for (int i = 0; i < TEST_ARRAYS_NUMBER; i++) {
        result &= testQuickSort(testArrays[i], ARRAYS_SIZE);
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
    printf("Hello, World!\n");
    return 0;
}
