#include <stdio.h>

float evaluatePolynom(float x) {
    float firstMultiplication = x * x;
    return firstMultiplication * (firstMultiplication + x) + firstMultiplication + x + 1;
}

int main() {
    float x = 0;
    printf("Введите число: ");  
    scanf("%f", &x);
    printf("Результат равен %f\n", evaluatePolynom(x));
    return 0;
}
