#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void addValue(List **head, const Value value) {
    if (head == NULL) {
        return;
    }
    while (*head != NULL && (*head)->value < value) {
        head = &(*head)->next;
    }
    List *newValue = calloc(1, sizeof(List));
    newValue->value = value;
    newValue->next = *head;
    *head = newValue;
}

void deleteValue(List **head, const Value value) {
    if (head == NULL) {
        return;
    }
    while (*head != NULL && (*head)->value < value) {
        head = &(*head)->next;
    }
    if (*head == NULL || (*head)->value != value) {
        return;
    }
    while (*head != NULL && (*head)->value == value) {
        List *toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
    }
}

void printList(List *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void freeList(List *head) {
    if (head == NULL) {
        return;
    }
    freeList(head->next);
    free(head);
}