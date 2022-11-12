#ifndef INC_9_1_LIST_H
#define INC_9_1_LIST_H

typedef int Value;
typedef char* Key;
typedef const char* ConstKey;
typedef const int ConstValue;

typedef struct List {
    Key key;
    Value value;
    struct List *next;
} List;

int length(List **head);

void addEntry(List **head, ConstKey key, ConstValue value);

void deleteEntry(List **head, ConstKey key);

List *findEntry(List **head, ConstKey key);

void printList(List *head);

void freeList(List *head);

#endif //INC_9_1_LIST_H
