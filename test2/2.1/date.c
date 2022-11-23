#include <stdio.h>
#include "date.h"

int cmpDates(Date left, Date right) {
    if (left.year != right.year)
        return left.year - right.year;
    if (left.month != right.month)
        return left.month - right.month;
    return left.day - right.day;
}

Date findMaxDate(FILE *in) {
    Date maxDate = {0};
    Date curDate = {0};
    while (fscanf(in, "%d.%d.%d", &curDate.day, &curDate.month, &curDate.year) == 3) {
        if (cmpDates(maxDate, curDate) < 0) {
            maxDate.day = curDate.day;
            maxDate.month = curDate.month;
            maxDate.year = curDate.year;
        }
    }
    return maxDate;
}
