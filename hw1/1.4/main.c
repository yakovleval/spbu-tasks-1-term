#include <stdio.h>
#define MAX_SUM 27

int digitsSum(int number) {
    return number % 10 + number / 10 % 10 + number / 100 % 10;
}

int happyTickets() {
    int numberOfSums[MAX_SUM + 1] = {0};
    for (int firstHalf = 0; firstHalf < 1000; firstHalf++) {
        numberOfSums[digitsSum(firstHalf)]++;
    }
    int answer = 0;
    for (int i = 0; i <= MAX_SUM; i++) {
        answer += numberOfSums[i] * numberOfSums[i];
    }
    return answer;
}

int main() {
    printf("количество счастливых билетов равно %d\n", happyTickets());
    return 0;
}
