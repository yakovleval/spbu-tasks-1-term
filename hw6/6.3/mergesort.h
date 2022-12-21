#ifndef INC_6_3_MERGESORT_H
#define INC_6_3_MERGESORT_H
#include "product.h"

enum SORT_BY {
    NAME = 0,
    NUMBER = 1
};

int compare(Product *left, Product *right, enum SORT_BY compareBy);
Product *merge(Product *left, Product *right, enum SORT_BY sortBy);
void split(Product *list, Product **leftPart, Product **rightPart);
void mergeSort(Product **head, enum SORT_BY sortBy);

#endif //INC_6_3_MERGESORT_H
