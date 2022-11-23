#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "date.h"
#define FILENAME "test.txt"

void writeDates(const char **dates, int size) {
    FILE *out = fopen(FILENAME, "w");
    for (int i = 0; i < size; i++) {
        fprintf(out, "%s", dates[i]);
        fprintf(out, "\n");
    }
    fclose(out);
}

bool testOneDate() {
    const char *dates[] = {"01.01.1970"};
    writeDates(dates, sizeof(dates)/sizeof(const char*));
    FILE *in = fopen(FILENAME, "r");
    Date maxDate = findMaxDate(in);
    bool result = maxDate.year == 1970 &&
            maxDate.month == 01 &&
            maxDate.day == 01;
    if (!result)
        printf("testOneDate failed\n");
    return result;
}

bool testDays() {
    const char *dates[] = {"01.01.1970", "02.01.1970", "03.01.1970", "04.01.1969"};
    writeDates(dates, sizeof(dates)/sizeof(const char*));
    FILE *in = fopen(FILENAME, "r");
    Date maxDate = findMaxDate(in);
    bool result = maxDate.year == 1970 &&
                  maxDate.month == 01 &&
                  maxDate.day == 03;
    if (!result)
        printf("testDays failed\n");
    return result;
}

bool testMonths() {
    const char *dates[] = {"10.01.1970", "01.02.1970", "01.03.1970", "01.04.1969"};
    writeDates(dates, sizeof(dates)/sizeof(const char*));
    FILE *in = fopen(FILENAME, "r");
    Date maxDate = findMaxDate(in);
    bool result = maxDate.year == 1970 &&
                  maxDate.month == 03 &&
                  maxDate.day == 01;
    if (!result)
        printf("testMonths failed\n");
    return result;
}

bool testYears() {
    const char *dates[] = {"01.10.1970", "20.12.1971", "01.01.1972", "01.04.1969"};
    writeDates(dates, sizeof(dates)/sizeof(const char*));
    FILE *in = fopen(FILENAME, "r");
    Date maxDate = findMaxDate(in);
    bool result = maxDate.year == 1972 &&
                  maxDate.month == 01 &&
                  maxDate.day == 01;
    if (!result)
        printf("testYears failed\n");
    return result;
}

bool isPassed() {
    return testOneDate() &&
    testDays() &&
    testMonths() &&
    testYears();
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (isPassed())
        printf("тесты пройдены\n");
}
