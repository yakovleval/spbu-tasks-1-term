#include "tree.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

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
    int balance = right->balance;
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

Node *addNewNode(Node *node, ConstKey key, ConstValue value) {
    if (node == NULL) {
        Node *newNode = calloc(1, sizeof(Node));
        newNode->key = calloc(strlen(key) + 1, sizeof(char));
        newNode->value = calloc(strlen(value) + 1, sizeof(char));
        strcpy(newNode->key, key);
        strcpy(newNode->value, value);
        newNode->balance = 0;
        return newNode;
    } else if (strcmp(key, node->key) < 0) {
        node->leftChild = addNewNode(node->leftChild, key, value);
        node->balance--;
    } else {
        node->rightChild = addNewNode(node->rightChild, key, value);
        node->balance++;
    }
    return balance(node);
}

Node *addNode(Node *root, ConstKey key, ConstValue value) {
    Node *foundNode = findNode(root, key);
    if (foundNode != NULL) {
        free(foundNode->value);
        foundNode->value = calloc(strlen(value) + 1, sizeof(char));
        strcpy(foundNode->value, value);
        return root;
    }
    return addNewNode(root, key, value);
}

Node *deleteExistingNode(Node *node, ConstKey key) {
    if (node == NULL) {
        return NULL;
    }
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

        node->balance--;
        node->rightChild = deleteExistingNode(node->rightChild, key);
        return balance(node);
    } else if (strcmp(key, node->key) < 0) {
        node->balance++;
        node->leftChild = deleteExistingNode(node->leftChild, key);
        return balance(node);
    } else {
        node->balance--;
        node->rightChild = deleteExistingNode(node->rightChild, key);
        return balance(node);
    }
}

Node *deleteNode(Node *root, ConstKey key) {
    if (findNode(root, key) == NULL)
        return root;
    deleteExistingNode(root, key);
}
