#include <string.h>
#include "mergesort.h"

int compare(Person *left, Person *right, enum SORT_BY compareBy) {
    return compareBy == NAME ? strcmp(left->name, right->name) :
           strcmp(left->number, right->number);
}

Person *merge(Person *left, Person *right, enum SORT_BY sortBy) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    Person *result = NULL;
    if (compare(left, right, sortBy) <= 0) {
        result = left;
        result->next = merge(left->next, right, sortBy);
    } else {
        result = right;
        result->next = merge(left, right->next, sortBy);
    }
    return result;
}

void split(Person *list, Person **leftPart, Person **rightPart) {
    if (list == NULL || list->next == NULL) {
        *rightPart = list;
        *leftPart = NULL;
        return;
    }
    Person *slow = list;
    Person *fast = list->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *leftPart = list;
    *rightPart = slow->next;
    slow->next = NULL;
}

void mergeSort(Person **head, enum SORT_BY sortBy) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Person *left = NULL;
    Person *right = NULL;
    split(*head, &left, &right);
    mergeSort(&left, sortBy);
    mergeSort(&right, sortBy);
    *head = merge(left, right, sortBy);
}
