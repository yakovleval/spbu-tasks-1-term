#include "solution.h"

int recursiveFibonacci(const int index) {
    if (index <= 2)
    {
        return 1;
    }
    return recursiveFibonacci(index - 1) + recursiveFibonacci(index - 2);
}

int iterativeFibonacci(const int index) {
    int firstTerm = 1;
    int secondTerm = 1;
    int termSum = firstTerm + secondTerm;
    for (int i = 0; i < index - 1; i++)
    {
        firstTerm = secondTerm;
        secondTerm = termSum;
        termSum = firstTerm + secondTerm;
    }
    return firstTerm;
}
