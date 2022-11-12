#include "list.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int length(List **head) {
    if (head == NULL)
        return 0;
    int result = 0;
    while (*head != NULL) {
        result++;
        head = &(*head)->next;
    }
    return result;
}

void addEntry(List **head, ConstKey key, ConstValue value) {
    if (head == NULL) {
        return;
    }
    while (*head != NULL) {
        head = &(*head)->next;
    }
    List *newValue = calloc(1, sizeof(List));
    newValue->key = calloc(strlen(key) + 1, sizeof(char));
    strcpy(newValue->key, key);
    newValue->value = value;
    newValue->next = *head;
    *head = newValue;
}

void deleteEntry(List **head, ConstKey key) {
    if (head == NULL) {
        return;
    }
    while (*head != NULL && (*head)->key != key) {
        *head = (*head)->next;
    }
    if (*head != NULL) {
        free((*head)->key);
        free(*head);
    }
}

List *findEntry(List **head, ConstKey key) {
    if (head == NULL)
        return NULL;
    while (*head != NULL && strcmp((*head)->key, key) != 0)
        head = &(*head)->next;
    return *head;
}

void printList(List *head) {
    while (head != NULL) {
        printf("%s - %d\n", head->key, head->value);
        head = head->next;
    }
}

void freeList(List *head) {
    if (head == NULL) {
        return;
    }
    freeList(head->next);
    free(head->key);
    free(head);
}
