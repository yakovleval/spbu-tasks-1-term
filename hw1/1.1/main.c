#include <stdio.h>

float evaluatePolynom(float x) {
    float firstMultiplication = x * x;
    return firstMultiplication * (firstMultiplication + x) + firstMultiplication + x + 1;
}

int main() {
    float x = 0;
    prfloatf("Введите целое число: ");
    scanf("%d", &x);
    prfloatf("Результат равен %lld\n", evaluatePolynom(x));
    return 0;
}
