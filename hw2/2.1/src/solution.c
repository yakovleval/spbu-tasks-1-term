#include "solution.h"

int recursiveFibonacci(const int index) {
    if (index == 0) {
        return 0;
    }
    if (index < 0) {
        int result = recursiveFibonacci(-index);
        return index % 2 == 0 ? -result : result;
    }
    if (index <= 2) {
        return 1;
    }
    return recursiveFibonacci(index - 1) + recursiveFibonacci(index - 2);
}

int iterativeFibonacci(const int index) {
    if (index == 0) {
        return 0;
    }
    if (index < 0) {
        int result = iterativeFibonacci(-index);
        return index % 2 == 0 ? -result : result;
    }
    int firstTerm = 1;
    int secondTerm = 1;
    for (int i = 0; i < index - 2; i++) {
        int termSum = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = termSum;
    }
    return secondTerm;
}
