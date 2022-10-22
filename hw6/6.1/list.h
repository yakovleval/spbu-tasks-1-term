#ifndef INC_6_1_LIST_H
#define INC_6_1_LIST_H

typedef int Value;

typedef struct List {
    Value value;
    struct List *next;
} List;

void addValue(List **head, Value value);

void deleteValue(List **head, Value value);

void printList(List *head);

void freeList(List *head);

#endif //INC_6_1_LIST_H
