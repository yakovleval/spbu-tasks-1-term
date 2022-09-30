#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

double powerLinear(const int base, const int power) {
    if (base == 0) {
        return 0;
    }
    if (power == 0) {
        return 1;
    }
    double result = 1;
    for (int absPower = abs(power); absPower > 0; absPower--) {
        result *= base;
    }
    return power > 0 ? result : (1.0 / result);
}

double absPowerLogarithmic(const int base, const int absPower) {
    if (absPower == 0) {
        return 1;
    }
    if (absPower % 2 == 1) {
        return absPowerLogarithmic(base, absPower - 1) * base;
    } else {
        double result = absPowerLogarithmic(base, absPower / 2);
        return result * result;
    }
}
double powerLogarithmic(const int base, const int power) {
    if (base == 0) {
        return 0;
    }
    double result = absPowerLogarithmic(base, abs(power));
    return power < 0 ? 1.0 / result : result;
}

bool testPower(const int base, const int power, const double answer) {
    return powerLinear(base, power) == answer &&
           powerLogarithmic(base, power) == answer;
}

bool isPassed() {
    return
            testPower(0, 1, 0) &&
            testPower(1, 0, 1) &&
            testPower(1, 1, 1) &&
            testPower(2, 10, 1024) &&
            testPower(-1, 0, 1) &&
            testPower(-2, 10, 1024) &&
            testPower(-2, 9, -512) &&
            testPower(1, -1, 1) &&
            testPower(2, -10, 1.0 / 1024) &&
            testPower(-2, -10, 1.0 / 1024) &&
            testPower(2, -30, 1.0 / 1073741824);
}

int main() {
    if (!isPassed()) {
        printf("Тесты не пройдены\n");
        return 0;
    } else {
        printf("Тесты пройдены\n");
    }
    return 0;
}
