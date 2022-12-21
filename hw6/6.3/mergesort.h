#ifndef INC_6_3_MERGESORT_H
#define INC_6_3_MERGESORT_H
#include "product.h"

enum SORT_BY {
    NAME = 0,
    NUMBER = 1
};

enum ORDER {
    ASCENDING = 1, DESCENDGING = -1
};

void mergeSort(Product **head, enum SORT_BY sortBy, enum ORDER order);

#endif //INC_6_3_MERGESORT_H
