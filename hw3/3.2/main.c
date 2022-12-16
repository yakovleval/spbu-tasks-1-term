#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define TEST_ARRAY_SIZE 50
#define MOD 100

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

bool binSearch(const int *array, const int size, const int key) {
    // leftBound <= key, rightBound > key
    int leftBound = 0;
    int rightBound = size;
    while (rightBound - leftBound > 1) {
        int middle = (leftBound + rightBound) / 2;
        if (array[middle] <= key) {
            leftBound = middle;
        } else {
            rightBound = middle;
        }
    }
    return array[leftBound] == key;
}

bool doesExist(const int *array, const int size, const int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return true;
        }
    }
    return false;
}

bool testBinSearch(const int *array, const int size, const int key) {
    return doesExist(array, size, key) == binSearch(array, size, key);
}

void generateRandomArray(int *array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % MOD;
    }
}

bool isPassed() {
    int testArray[TEST_ARRAY_SIZE] = {0};
    int testKeys[TEST_ARRAY_SIZE] = {0};
    generateRandomArray(testArray, TEST_ARRAY_SIZE);
    generateRandomArray(testKeys, TEST_ARRAY_SIZE);

    quickSort(testArray, 0, TEST_ARRAY_SIZE - 1);
    bool result = true;
    for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
        result &= testBinSearch(testArray, TEST_ARRAY_SIZE, testKeys[i]);
    }
    return result;
}


int main() {
    setlocale(LC_ALL, "RU-ru");
    srand(239);

    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }

    printf("введите размер массива и кол-во случайных элементов (n и k): \n");
    int n = 0, k = 0;
    scanf("%d%d", &n, &k);
    while (n < 0 || k < 0) {
        printf("n и k должны быть неотрицательными\n");
        printf("введите размер массива и кол-во случайных элементов (n и k): \n");
        scanf("%d%d", &n, &k);
    }
    int *randomArray = calloc(n, sizeof(int));
    int *randomNumbers = calloc(k, sizeof(int));

    for (int i = 0; i < n; i++) {
        randomArray[i] = rand() % MOD;
    }
    for (int i = 0; i < k; i++) {
        randomNumbers[i] = rand() % MOD;
    }

    quickSort(randomArray, 0, n - 1);

    printf("отсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", randomArray[i]);
    }
    printf("\n");

    for (int i = 0; i < k; i++) {
        if (binSearch(randomArray, n, randomNumbers[i])) {
            printf("%d -- содержится в массиве\n", randomNumbers[i]);
        } else {
            printf("%d -- не содержится в массиве\n", randomNumbers[i]);
        }
    }

    free(randomNumbers);
    free(randomArray);
    return 0;
}
