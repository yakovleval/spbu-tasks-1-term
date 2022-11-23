#include "date.h"

int cmpDates(Date left, Date right) {
    if (left.year != right.year)
        return left.year - right.year;
    if (left.month != right.month)
        return left.month - right.month;
    return left.day - right.day;
}
