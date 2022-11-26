#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void freeNode(Node *node) {
    if (node == NULL)
        return;
    free(node->value);
    free(node->key);
    free(node);
}

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->leftChild);
    freeTree(root->rightChild);
    freeNode(root);
}

Node *findNode(Node *root, ConstKey key) {
    if (root == NULL)
        return NULL;
    int comparison = strcmp(key, root->key);
    if (comparison == 0)
        return root;
    return comparison < 0 ? findNode(root->leftChild, key) : findNode(root->rightChild, key);
}

Value findValue(Node *root, ConstKey key) {
    Node *foundNode = findNode(root, key);
    return foundNode == NULL ? NULL : foundNode->value;
}

Node *rotateLeft(Node *node) {
    Node *right = node->rightChild;
    Node *rleft = right->leftChild;
    right->leftChild = node;
    node->rightChild = rleft;
    if (right->balance == 0) {
        node->balance = 1;
        right->balance = -1;
    } else {
        node->balance = 0;
        right->balance = 0;
    }
    return right;
}

Node *rotateRight(Node *node) {
    Node *left = node->leftChild;
    Node *lright = left->rightChild;
    left->rightChild = node;
    node->leftChild = lright;
    if (left->balance == 0) {
        node->balance = -1;
        left->balance = 1;
    } else {
        node->balance = 0;
        left->balance = 0;
    }
    return left;
}

Node *balance(Node *node) {
    if (node->balance == 2) {
        if (node->rightChild->balance >= 0)
            return rotateLeft(node);
        node->rightChild = rotateRight(node->rightChild);
        return rotateLeft(node);
    }
    if (node->balance == -2) {
        if (node->leftChild->balance <= 0)
            return rotateRight(node);
        node->leftChild = rotateLeft(node->leftChild);
        return rotateRight(node);
    }
    return node;
}

Node *addNode(Node *node, ConstKey key, ConstValue value, bool *isBalanceChanged) {
    if (node == NULL) {
        Node *newNode = calloc(1, sizeof(Node));
        newNode->key = calloc(strlen(key) + 1, sizeof(char));
        newNode->value = calloc(strlen(value) + 1, sizeof(char));
        strcpy(newNode->key, key);
        strcpy(newNode->value, value);
        newNode->balance = 0;
        return newNode;
    }
    int comparison = strcmp(key, node->key);
    int balanceDelta = 0;
    if (comparison == 0) {
        free(node->value);
        node->value = calloc(strlen(value) + 1, sizeof(char));
        strcpy(node->value, value);
        *isBalanceChanged = false;
        return node;
    } else if (comparison < 0) {
        node->leftChild = addNode(node->leftChild, key, value, isBalanceChanged);
        balanceDelta = -1;
    } else {
        node->rightChild = addNode(node->rightChild, key, value, isBalanceChanged);
        balanceDelta = 1;
    }
    if (!*isBalanceChanged)
        return node;
    node->balance += balanceDelta;
    if (node->balance != 1 && node->balance != -1)
        *isBalanceChanged = false;
    return balance(node);
}

Node *add(Node *root, ConstKey key, ConstValue value) {
    if (key == NULL || value == NULL)
        return NULL;
    bool balanceChanged = true;
    return addNode(root, key, value, &balanceChanged);
}

Node *deleteNode(Node *node, ConstKey key, bool *isBalanceChanged) {
    if (node == NULL) {
        *isBalanceChanged = false;
        return NULL;
    }
    int balanceDelta = 0;
    if (strcmp(key, node->key) == 0) {
        if (node->rightChild == NULL) {
            Node *new = node->leftChild;
            freeNode(node);
            return new;
        }
        if (node->leftChild == NULL) {
            Node *new = node->rightChild;
            freeNode(node);
            return new;
        }

        Node *next = node->rightChild;
        while (next->leftChild != NULL) {
            next = next->leftChild;
        }

        Key tmpKey = node->key;
        node->key = next->key;
        next->key = tmpKey;

        Value tmpVal = node->value;
        node->value = next->value;
        next->value = tmpVal;

        node->rightChild = deleteNode(node->rightChild, key, isBalanceChanged);
        balanceDelta = -1;
    } else if (strcmp(key, node->key) < 0) {
        node->leftChild = deleteNode(node->leftChild, key, isBalanceChanged);
        balanceDelta = 1;
    } else {
        node->rightChild = deleteNode(node->rightChild, key, isBalanceChanged);
        balanceDelta = -1;
    }
    if (!*isBalanceChanged)
        return node;
    node->balance += balanceDelta;
    if (node->balance == 1 || node->balance == -1)
        *isBalanceChanged = false;
    return balance(node);
}

Node *delete(Node *root, ConstKey key) {
    bool balanceChanged = true;
    return deleteNode(root, key, &balanceChanged);
}
