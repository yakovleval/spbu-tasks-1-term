#include <string.h>
#include "mergesort.h"

int compare(Product *left, Product *right, enum SORT_BY compareBy) {
    return compareBy == NAME ? strcmp(left->name, right->name) :
           strcmp(left->number, right->number);
}

Product *merge(Product *left, Product *right, enum SORT_BY sortBy) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    Product *result = NULL;
    if (compare(left, right, sortBy) <= 0) {
        result = left;
        result->next = merge(left->next, right, sortBy);
    } else {
        result = right;
        result->next = merge(left, right->next, sortBy);
    }
    return result;
}

void split(Product *list, Product **leftPart, Product **rightPart) {
    if (list == NULL || list->next == NULL) {
        *rightPart = list;
        *leftPart = NULL;
        return;
    }
    Product *slow = list;
    Product *fast = list->next;
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

void mergeSort(Product **head, enum SORT_BY sortBy) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Product *left = NULL;
    Product *right = NULL;
    split(*head, &left, &right);
    mergeSort(&left, sortBy);
    mergeSort(&right, sortBy);
    *head = merge(left, right, sortBy);
}
