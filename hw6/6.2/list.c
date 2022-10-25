#include <stddef.h>
#include <stdlib.h>
#include "list.h"

List** addNodes(int nodesNumber) {
    List *list = NULL;
    List **head = &list;
    *head = calloc(1, sizeof(Value));
    (*head)->value = nodesNumber;
    (*head)->next = NULL;
    List *last = *head;
    head = &(*head)->next;
    for (int i = 1; i < nodesNumber; i++) {
        *head = calloc(1, sizeof(Value));
        (*head)->value = i;
        (*head)->next = NULL;
        head = &(*head)->next;
    }
    *head = last;
    return &(*head)->next;

}

void deleteNode(List **head) {
    if (head == NULL || *head == NULL) {
        return;
    }
    List *toDelete = *head;
    *head = (*head)->next;
    free(toDelete);
}
