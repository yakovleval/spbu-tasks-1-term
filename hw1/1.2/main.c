#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int findQuotient(int dividend, int divisor) {
    bool isDividendNegative = dividend < 0;
    bool isDivisorNegative = divisor < 0;
    dividend = abs(dividend);
    divisor = abs(divisor);
    int quotient = 0;
    int remainder = 0;

    while ((remainder = dividend - quotient * divisor) >= divisor) {
        quotient++;
    }
    if (isDividendNegative && remainder > 0) {
        quotient++;
    }
    // if exactly one of them is negative
    if (isDividendNegative ^ isDivisorNegative) {
        quotient = -quotient;
    }
    return quotient;
}

int main() {
    int dividend = 0;
    int divisor = 0;
    do {
        printf("введите целые делимое и делитель (делитель не может быть 0): ");
        scanf("%d%d", &dividend, &divisor);
    } while (divisor == 0);
    printf("Неполное частное равно %d\n", findQuotient(dividend, divisor));
    return 0;
}
