#include <stdio.h>

void swap(int *left, int *right) {
    int tmp = *left;
    *left = *right;
    *right = tmp;
}

//reverses [start, end) subarray
void reverseSubarray(int *array, int start, int end) {
    end--;
    while (start < end) {
        swap(&array[start], &array[end]);
        start++, end--;
    }
}

int main() {
    int firstSegment = 0, secondSegment = 0;
    printf("введите длины первого и второго отрезков массива (m и n): ");
    scanf("%d%d", &firstSegment, &secondSegment);
    while (firstSegment < 0 || secondSegment < 0) {
        printf("длины отрезков не могут быть отрицательными\n");
        printf("введите длины первого и второго отрезков массива (m и n): ");
        scanf("%d%d", &firstSegment, &secondSegment);
    }

    int length = firstSegment + secondSegment;
    int array[length];

    printf("введите элементы массива через пробел: \n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }

    reverseSubarray(array, 0, firstSegment);
    reverseSubarray(array, firstSegment, length);
    reverseSubarray(array, 0, length);

    printf("результирующий массив равен: \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
