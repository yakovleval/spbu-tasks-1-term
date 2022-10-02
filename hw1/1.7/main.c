#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

void eratosthenesSieve(int maxNumber, bool *isPrime) {
    for (int i = 0; i <= maxNumber; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= maxNumber; i++) {
        if (isPrime[i] && (long long)i * i <= maxNumber) {
            for (int j = i * i; j <= maxNumber; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    int maxNumber = 0;
    printf("Введите число, до которого нужно вывести простые: ");
    scanf("%d", &maxNumber);
    if (maxNumber <= 1) {
        printf("нет простых чисел, непревосходящих данное\n");
        return 0;
    }
    printf("простые числа до %d: \n", maxNumber);
    bool isPrime[maxNumber + 1];
    eratosthenesSieve(maxNumber, isPrime);
    for (int i = 0; i <= maxNumber; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}
