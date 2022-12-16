#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TEST_ARRAYS_NUMBER 10
#define ARRAYS_SIZE 50

typedef int Error;

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

    int pivot = array[leftBound];

    int leftPartIndex = 0;
    int rightPartIndex = 0;
    partition(array, leftBound, rightBound, &leftPartIndex, &rightPartIndex, pivot);
    quickSort(array, leftBound, leftPartIndex);
    quickSort(array, rightPartIndex, rightBound);
}

Error mostFrequent(const int *array, const int size, int *result) {
    int *sortedArray = calloc(size, sizeof(int));
    if (sortedArray == NULL)
        return 1;
    memcpy(sortedArray, array, size * sizeof(int));
    quickSort(sortedArray, 0, size - 1);
    int answer = sortedArray[0];
    int current = answer;
    int maxCount = 1;
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (sortedArray[i] == current) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                answer = sortedArray[i - 1];
            }
            count = 1;
            current = sortedArray[i];
        }
    }
    if (count > maxCount) {
        maxCount = count;
        answer = sortedArray[size - 1];
        count = 1;
    }
    free(sortedArray);
    *result = answer;
    return 0;
}

bool checkMostFrequent(const int *array, const int size, const int element) {
    int maxFrequency = 0;
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (array[j] == array[i]) {
                count++;
            }
        }
        if (count > maxFrequency) {
            maxFrequency = count;
        }
    }
    int countElement = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            countElement++;
        }
    }
    return countElement == maxFrequency;
}

void generateRandomArray(int *array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % size;
    }
}

bool testMostFrequent(const int *array, const int size) {
    int result = 0;
    int error = mostFrequent(array, size, &result);
    if (error != 0)
        return false;
    return checkMostFrequent(array, size, result);
}

bool testRandomArrays() {
    int *testArrays[TEST_ARRAYS_NUMBER] = {NULL};
    for (int i = 0; i < TEST_ARRAYS_NUMBER; i++) {
        testArrays[i] = calloc(ARRAYS_SIZE, sizeof(int));
        if (testArrays[i] == NULL)
            return false;
        generateRandomArray(testArrays[i], ARRAYS_SIZE);
    }
    bool result = true;
    for (int i = 0; i < TEST_ARRAYS_NUMBER; i++) {
        result &= testMostFrequent(testArrays[i], ARRAYS_SIZE);
    }

    for (int i = 0; i < TEST_ARRAYS_NUMBER; i++) {
        free(testArrays[i]);
    }
    return result;
}

bool testOneElement() {
    const int testArray[] = {239};
    return testMostFrequent(testArray, sizeof(testArray) / sizeof(int));
}

bool testAllEqual() {
    const int testArray[] = {2, 2, 2, 2, 2};
    return testMostFrequent(testArray, sizeof(testArray) / sizeof(int));
}

bool isPassed() {
    return testRandomArrays() &&
           testOneElement() &&
           testAllEqual();
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    printf("тесты пройдены\n");
    return 0;
}
