#include <stdio.h>

long long evaluatePolynom(int x) {
    long long firstMultiplication = x * x;
    return firstMultiplication * (firstMultiplication + x) + firstMultiplication + x + 1;
}

int main() {
    int x = 0;
    printf("Введите целое число: ");
    scanf("%d", &x);
    printf("Результат равен %lld\n", evaluatePolynom(x));
    return 0;
}
