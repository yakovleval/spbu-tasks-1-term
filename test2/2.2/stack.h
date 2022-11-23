#ifndef INC_2_2_STACK_H
#define INC_2_2_STACK_H
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int push(Node **Last, int value);

int pop(Node **head, int *value);

int top(const Node *head, int *value);

bool isEmpty(const Node *head);

int deleteAll(Node **head);

#endif //INC_2_2_STACK_H
