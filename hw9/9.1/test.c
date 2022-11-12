#include <malloc.h>
#include <string.h>
#include "test.h"
#include "table.h"

int expectedFrequency(const char *key, const char **array, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(key, array[i]) == 0)
            count++;
    }
    return count;
}

int cmpDouble(double left, double right) {
    const double eps = 1e6;
    if (-eps < right - left && right - left < eps)
        return 0;
    return left < right ? -1 : 1;
}

bool testMetrics(Table *table, const char **test, int size, double expectedLoad, double expectedAvg) {
    bool result = true;
    for (int i = 0; i < size; i++) {
        result &= frequency(table, test[i]) == expectedFrequency(test[i], test, size);
    }
    result &= cmpDouble(load(table), expectedLoad) == 0 &&
            cmpDouble(averageLen(table), expectedAvg) == 0;
    return result;
}

bool test(const char **test, int size, double loadAns, double avgAns) {
    Table *table = calloc(1, sizeof(Table));
    for (int i = 0; i < size; i++) {
        add(table, test[i]);
    }
    bool result = testMetrics(table, test, size, loadAns,avgAns);
    freeTable(table);
    return result;
}

bool isPassed() {
    const char *test1[] = {"a", "a", "a", "b", "b", "c"};
    const char *test2[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    const char *test3[] = {"abc", "bca", "cab", "cba"};
    return test(test1, sizeof(test1)/sizeof(const char*), 0.6, 1.0) &&
    test(test2, sizeof(test2)/sizeof(const char*), 1.0, 1.0) &&
    test(test3, sizeof(test3)/sizeof(const char*), 0.4, 4.0);
}
