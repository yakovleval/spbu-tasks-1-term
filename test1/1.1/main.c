#include <stdio.h>
#include <locale.h>

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

int main() {
    setlocale(LC_ALL, "RU-ru");
    printf("Hello, World!\n");
    return 0;
}
