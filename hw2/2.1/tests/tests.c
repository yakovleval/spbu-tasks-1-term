#include "../CuTestLib/CuTest.h"
#include "../src/solution.h"
#include <stddef.h>

void TestFibonacci(CuTest *tc) {
    int  PosFibonacciNumbers[] = {0,1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int NegFibonacciNumbers[] = {0, 1, -1, 2, -3, 5, -8, 13};
    for (int i = 0; i < sizeof(PosFibonacciNumbers) / sizeof(int); i++) {
        CuAssertIntEquals(tc, PosFibonacciNumbers[i], iterativeFibonacci(i));
    }
    for (int i = 0; i < sizeof(NegFibonacciNumbers) / sizeof(int); i++) {
        CuAssertIntEquals(tc, NegFibonacciNumbers[i], iterativeFibonacci(-i));
    }
}

void TestRecursiveFibonacci(CuTest *tc) {
    int PosFibonacciNumbers[] = {0,1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int NegFibonacciNumbers[] = {0, 1, -1, 2, -3, 5, -8, 13};
    for (int i = 0; i < sizeof(PosFibonacciNumbers) / sizeof(int); i++) {
        CuAssertIntEquals(tc, PosFibonacciNumbers[i], recursiveFibonacci(i));
    }
    for (int i = 0; i < sizeof(NegFibonacciNumbers) / sizeof(int); i++) {
        CuAssertIntEquals(tc, NegFibonacciNumbers[i], recursiveFibonacci(-i));
    }
}
