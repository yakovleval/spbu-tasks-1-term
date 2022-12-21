#ifndef INC_6_3_MERGESORT_H
#define INC_6_3_MERGESORT_H
#include "person.h"

enum SORT_BY {
    NAME = 0,
    NUMBER = 1
};

int compare(Person *left, Person *right, enum SORT_BY compareBy);
Person *merge(Person *left, Person *right, enum SORT_BY sortBy);
void split(Person *list, Person **leftPart, Person **rightPart);
void mergeSort(Person **head, enum SORT_BY sortBy);

#endif //INC_6_3_MERGESORT_H
