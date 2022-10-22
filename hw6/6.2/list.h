#ifndef INC_6_2_LIST_H
#define INC_6_2_LIST_H

typedef int Value;

typedef struct List {
    Value value;
    struct List *next;
} List;

List** addNodes(int nodesNumber);

void deleteNode(List **head);

#endif //INC_6_2_LIST_H
