#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void add(int *dest, const int *source, const int buffersSize) {
    for (int i = 0; i < buffersSize - 1; i++) {
        dest[i] += source[i];
        dest[i + 1] += dest[i] / 2;
        dest[i] %= 2;
    }
    dest[buffersSize - 1] += source[buffersSize - 1];
    dest[buffersSize - 1] %= 2;
}

void decimalToBinary(int *binary, const int size, int decimal) {
    for (int i = 0; i < size; i++) {
        binary[i] = decimal & 1;
        decimal >>= 1;
    }
}

int binaryToDecimal(const int *binary, const int size) {
    int decimal = 0;
    for (int i = 0; i < size; i++) {
        decimal += (1 << i) * binary[i];
    }
    return decimal;
}

void printBinary(const int *binary, const int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", binary[i]);
    }
    printf("\n");
}

bool isPassed() {
//    const int buffersSize = 32;
//    const int testsNumber = 7;
#define BUFFERS_SIZE 32
#define TESTS_NUMBER 7
    int decimal1[TESTS_NUMBER] = {0, 1, 10, 10, -239, 2147483647, -2147483647 - 1};
    int decimal2[TESTS_NUMBER] = {0, -1, 15, -15, 239, -2147483647 - 1, 1};
    int *binary1 = (int *) calloc(BUFFERS_SIZE, sizeof(int));
    int *binary2 = (int *) calloc(BUFFERS_SIZE, sizeof(int));
    bool result = true;
    for (int i = 0; i < TESTS_NUMBER; i++) {
        decimalToBinary(binary1, BUFFERS_SIZE, decimal1[i]);
        decimalToBinary(binary2, BUFFERS_SIZE, decimal2[i]);
        add(binary1, binary2, BUFFERS_SIZE);
        result &= (decimal1[i] + decimal2[i]) == binaryToDecimal(binary1, BUFFERS_SIZE);
    }
    free(binary1);
    free(binary2);
    return result;
}

int main() {
    srand(239);
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    printf("тесты пройдены\n");
    const int buffersSize = 32;
    printf("введите 2 целых числа:\n");
    int decimal1 = 0;
    int decimal2 = 0;
    scanf("%d %d", &decimal1, &decimal2);

    int *binary1 = (int *) calloc(buffersSize, sizeof(int));
    int *binary2 = (int *) calloc(buffersSize, sizeof(int));
    decimalToBinary(binary1, buffersSize, decimal1);
    decimalToBinary(binary2, buffersSize, decimal2);

    printf("бинарное представление первого числа:\n");
    printBinary(binary1, buffersSize);
    printf("бинарное представление второго числа:\n");
    printBinary(binary2, buffersSize);
    add(binary1, binary2, buffersSize);
    printf("бинарное представление суммы:\n");
    printBinary(binary1, buffersSize);
    printf("десятичное представление суммы: %d\n", binaryToDecimal(binary1, buffersSize));

    free(binary1);
    free(binary2);
    return 0;
}