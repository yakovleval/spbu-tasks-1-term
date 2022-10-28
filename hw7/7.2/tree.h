#ifndef INC_7_2_TREE_H
#define INC_7_2_TREE_H

#include <stdbool.h>
#include <stdio.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    bool isOp;
    int value;
    char op;
} Node;

typedef int Error;

Error buildTree(Node **root, FILE *in);

void printTree(Node *root);

int evaluateTree(Node *root);

void freeTree(Node *root);

#endif //INC_7_2_TREE_H
