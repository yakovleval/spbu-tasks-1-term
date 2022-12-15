#include <stdio.h>
#include <locale.h>
#include <memory.h>

#define MAX_BUF 256
#define INT_LEN 8

//big-endian
int stringToInt(const char *buffer, int size) {
    int tenPower = 1;
    int result = 0;
    for (int i = 0; i < size; i++) {
        if ('0' <= buffer[size - 1 - i] && buffer[size - 1 - i] <= '9') {
            result += (buffer[size - 1 - i] - '0') * tenPower;
            tenPower *= 10;
        }
    }
    return result;
}

int parseNumber(const char *buffer, int *strIndex, int size, int *result) {
    char number[INT_LEN] = {0};
    int numberIndex = 0;
    if ('0' > buffer[*strIndex] || buffer[*strIndex] > '9')
        return 1;
    while (numberIndex < INT_LEN && *strIndex < size) {
        if ('0' <= buffer[*strIndex] && buffer[*strIndex] <= '9') {
            number[numberIndex] = buffer[*strIndex];
            numberIndex++;
            (*strIndex)++;
        }
        else
            break;
    }
    *result = stringToInt(number, INT_LEN);
    return 0;
}

int parseLine(const char *buffer, int size, int *quantity, int *price) {
    int strIndex = 0;
    while (strIndex < size && buffer[strIndex] != '\t')
        strIndex++;
    if (strIndex >= size)
        return 1;
    strIndex++;
    int error = parseNumber(buffer, &strIndex, size, quantity);
    if (error != 0)
        return error;
    if (buffer[strIndex] != '\t')
        return 1;
    strIndex++;
    error = parseNumber(buffer, &strIndex, size, price);
    if (error != 0)
        return error;
    if (buffer[strIndex] != '\n')
        return 1;
    return 0;
}



int main() {
    setlocale(LC_ALL, "RU-ru");
    FILE* in = fopen("order.txt", "r");
    char name[256];
    int quantity = 0, price = 0;
    char *buffer = NULL;
    size_t size = 0;
    long long sum = 0;
    while (getline(&buffer, &size, in) != -1) {
        int error = parseLine(buffer, strlen(buffer), &quantity, &price);
        if (error != 0) {
            printf("неверный формат файла\n");
            return 0;
        }
        sum += quantity * price;
        quantity = price = 0;
    }
    free(buffer);
    fclose(in);
    printf("сумма заказа: %lld\n", sum);
    return 0;
}
