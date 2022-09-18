#include "../CuTestLib/CuTest.h"
#include "../src/solution.h"
#include <stddef.h>

void TestFibonacci(CuTest *tc) {
    int fibonacciNumbers[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    for (int i = 0; i < 12; i++) {
        CuAssertIntEquals(tc, fibonacciNumbers[i], iterativeFibonacci(i + 1));
    }
}

void TestRecursiveFibonacci(CuTest *tc) {
    int fibonacciNumbers[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    for (int i = 0; i < 12; i++) {
        CuAssertIntEquals(tc, fibonacciNumbers[i], recursiveFibonacci(i + 1));
    }
}
