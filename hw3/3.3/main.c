#include <stdbool.h>
#include <locale.h>

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
               int *pLeftIndex, int *pRightIndex, const int pivot) {

    int leftIndex = leftBound;
    int rightIndex = rightBound;
    while (leftIndex <= rightIndex) {
        while (leftIndex <= rightBound && array[leftIndex] < pivot) {
            leftIndex++;
        }
        while (rightIndex >= leftBound && array[rightIndex] >= pivot) {
            rightIndex--;
        }
        if (leftIndex <= rightIndex) {
            const int tmp = array[leftIndex];
            array[leftIndex] = array[rightIndex];
            array[rightIndex] = tmp;
            leftIndex++;
            rightIndex--;
        }
    }
    *pLeftIndex = leftIndex;
    *pRightIndex = rightIndex;
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
    bool areAllEqual = true;
    for (int i = leftBound; i < rightBound; i++) {
        if (array[i] != array[i + 1]) {
            pivot = array[i] > array[i + 1] ? array[i] : array[i + 1];
            areAllEqual = false;
            break;
        }
    }

    if (areAllEqual) {
        return;
    }

    int leftPartIndex = 0;
    int rightPartIndex = 0;
    partition(array, leftBound, rightBound, &leftPartIndex, &rightPartIndex, pivot);
    quickSort(array, leftBound, rightPartIndex);
    quickSort(array, leftPartIndex, rightBound);
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

int main() {
    setlocale(LC_ALL, "RU-ru");
    printf("Hello, World!\n");
    return 0;
}
