#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define TEST_ARRAYS_NUMBER 10
#define ARRAYS_SIZE 50

// sorts segment [leftBound, rightBound] in array
void insertionSort(int *array, const int leftBound, const int rightBound) {
    for (int i = leftBound + 1; i <= rightBound; i++) {
        for (int j = i - 1; j >= leftBound && array[j] > array[j + 1]; j--) {
            const int tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
        }
    }
}

// parts segment [leftBound, rightBound] of array
// returns right bound of left part and left bound of right part
void partition(int *array, const int leftBound, const int rightBound,
               int *leftPartIndex, int *rightPartIndex, const int pivot) {

    int leftIndex = leftBound;
    int rightIndex = rightBound;
    while (leftIndex <= rightIndex) {
        while (leftIndex < rightBound && array[leftIndex] < pivot) {
            leftIndex++;
        }
        while (rightIndex > leftBound && array[rightIndex] > pivot) {
            rightIndex--;
        }
        if (leftIndex >= rightIndex) {
            if (leftIndex == rightIndex) {
                if (leftIndex == leftBound)
                    leftIndex++;
                else
                    rightIndex--;
            }
            break;
        }
        if (leftIndex < rightIndex) {
            const int tmp = array[leftIndex];
            array[leftIndex] = array[rightIndex];
            array[rightIndex] = tmp;
            leftIndex++;
            rightIndex--;
        }
    }
    *rightPartIndex = leftIndex;
    *leftPartIndex = rightIndex;
}

// sorts segment [leftBound, rightBound] in array
void quickSort(int *array, const int leftBound, const int rightBound) {
    const int blockSize = rightBound - leftBound + 1;
    if (blockSize <= 0) {
        return;
    }
    if (blockSize < 10) {
        insertionSort(array, leftBound, rightBound);
        return;
    }

    //chooses pivot
    int pivot = array[leftBound];

    int leftPartIndex = 0;
    int rightPartIndex = 0;
    partition(array, leftBound, rightBound, &leftPartIndex, &rightPartIndex, pivot);
    quickSort(array, leftBound, leftPartIndex);
    quickSort(array, rightPartIndex, rightBound);
}

bool isSorted(const int *array, const int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool testQuickSort(int *array, const int size) {
    quickSort(array, 0, size - 1);
    return isSorted(array, size);
}

void generateRandomArray(int *array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }
}

bool testSimpleArray() {
    int testArray[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    return testQuickSort(testArray, sizeof(testArray)/sizeof(int));
}

bool testRandomArrays() {
    int *testArrays[TEST_ARRAYS_NUMBER] = {NULL};
    for (int i = 0; i < TEST_ARRAYS_NUMBER; i++) {
        testArrays[i] = calloc(ARRAYS_SIZE, sizeof(int));
        generateRandomArray(testArrays[i], ARRAYS_SIZE);
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

bool testAllEqual() {
    int testArray[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    return testQuickSort(testArray, sizeof(testArray)/sizeof(int));
}

bool isPassed() {
    return testSimpleArray() &&
           testRandomArrays() &&
           testAllEqual();
}

int main() {
    srand(239);
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    printf("тесты пройдены\n");
}
