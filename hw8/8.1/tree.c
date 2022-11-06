#include "tree.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct Node {
    struct Node *leftChild;
    struct Node *rightChild;
    int key;
    char *value;
};

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->leftChild);
    freeTree(root->rightChild);
    free(root->value);
    free(root);
}

Node **findNode(Node **root, const Key key) {
    while (*root != NULL && (*root)->key != key) {
        root = (key < (*root)->key ? &(*root)->leftChild : &(*root)->rightChild);
    }
    return root;
}

char *findValue(Node *root, const int key) {
    Node *foundNode = *findNode(&root, key);
    return foundNode == NULL ? NULL : foundNode->value;
}

Error addNode(Node **root, const Key key, ConstValue value) {
    Node **node = findNode(root, key);
    if (*node == NULL) {
        *node = calloc(1, sizeof(Node));
        if (*node == NULL) {
            return 1;
        }
        (*node)->key = key;
        (*node)->leftChild = (*node)->rightChild = NULL;
    }
    if ((*node)->value == NULL || strcmp((*node)->value, value) != 0) {
        (*node)->value = calloc(strlen(value) + 1, sizeof(char));
        if ((*node)->value == NULL) {
            free(*node);
            return 1;
        }
        strcpy((*node)->value, value);
    }
    return 0;
}

void deleteNode(Node **root, const Key key) {
    Node **node = findNode(root, key);
    if (*node == NULL) {
        return;
    }
    if ((*node)->rightChild == NULL) {
        Node *nodeToDelete = *node;
        *node = (*node)->leftChild;
        free(nodeToDelete);
        return;
    }
    Node **next = &(*node)->rightChild;
    while ((*next)->leftChild != NULL) {
        next = &(*next)->leftChild;
    }

    Value tmpValue = (*node)->value;
    (*node)->value = (*next)->value;
    (*next)->value = tmpValue;

    Key tmpKey = (*node)->key;
    (*node)->key = (*next)->key;
    (*next)->key = tmpKey;

    Node *nodeToDelete = *next;
    *next = (*next)->rightChild;
    free(nodeToDelete->value);
    free(nodeToDelete);
}
