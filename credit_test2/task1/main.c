#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 257

const char romanDigits[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int romanValues[] = {1, 5, 10, 50, 100, 500, 1000};

int getValue(char digit) {
    for (int i = 0; i < sizeof(romanDigits) / sizeof(const char); i++) {
        if (digit == romanDigits[i])
            return romanValues[i];
    }
    return -1;
}

int romanToArabic(const char *romanNumber) {
    int length = strlen(romanNumber);
    int result = 0;
    for (int i = 0; i < length - 1; i++) {
        int value = getValue(romanNumber[i]);
        if (value == -1) {
            return -1;
        }
        if (value < getValue(romanNumber[i + 1]))
            result -= value;
        else
            result += value;
    }
    int lastCharValue = getValue(romanNumber[length - 1]);
    if (lastCharValue == -1) {
        return -1;
    }
    return result + lastCharValue;
}

bool isPassed() {
    char *romanNumber[] = {"I", "II", "III", "IV", "V", "IX", "XLVI", "DLXXXIII", "DCCCLXXXVIII", "MCMLXXXIX"};
    int answers[] = {1, 2, 3, 4, 5, 9, 46, 583, 888, 1989};
    for (int i = 0; i < sizeof(answers) / sizeof(int); i++) {
        if (romanToArabic(romanNumber[i]) != answers[i])
            return false;
    }
    return true;
}

int main() {
    char romanNumber[BUFFER_SIZE];
    if (!isPassed()) {
        printf("tests not passed\n");
        return 0;
    }
    printf("enter the roman number:\n");
    scanf("%256s", romanNumber);
    int result = 0;
    int length = strlen(romanNumber);
    for (int i = 0; i < length - 1; i++) {
        int value = getValue(romanNumber[i]);
        if (value == -1) {
            printf("incorrect roman number\n");
            return 0;
        }
        if (value < getValue(romanNumber[i + 1]))
            result -= value;
        else
            result += value;
    }
    int lastCharValue = getValue(romanNumber[length - 1]);
    if (lastCharValue == -1) {
        printf("incorrect roman number\n");
        return 0;
    }
    result += lastCharValue;
    printf("%d", result);
    return 0;
}
