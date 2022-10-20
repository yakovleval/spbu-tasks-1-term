#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node *next;
} Node;

int push(Node **Last, char value);

int pop(Node **head, char *value);

bool isEmpty(Node *head);

int deleteAll(Node **head);

#endif //STACK_STACK_H
