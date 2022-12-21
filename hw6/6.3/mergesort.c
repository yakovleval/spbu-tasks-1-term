#include <string.h>
#include "mergesort.h"

int compare(Product *left, Product *right, enum SORT_BY compareBy, enum ORDER order) {
    return compareBy == NAME ?
            order * strcmp(left->name, right->name) :
            order * (left->number - right->number);
}

Product *merge(Product *left, Product *right, enum SORT_BY sortBy, enum ORDER order) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    Product *result = NULL;
    if (compare(left, right, sortBy, order) <= 0) {
        result = left;
        result->next = merge(left->next, right, sortBy, order);
    } else {
        result = right;
        result->next = merge(left, right->next, sortBy, order);
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

void mergeSort(Product **head, enum SORT_BY sortBy, enum ORDER order) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Product *left = NULL;
    Product *right = NULL;
    split(*head, &left, &right);
    mergeSort(&left, sortBy, order);
    mergeSort(&right, sortBy, order);
    *head = merge(left, right, sortBy, order);
}
