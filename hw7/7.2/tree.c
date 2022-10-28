#include "tree.h"
#include <stdlib.h>
#include <string.h>

Error buildTree(Node **root, FILE *in) {
    if (root == NULL) {
        return 1;
    }
    while (true) {
        char currCh = (char) fgetc(in);
        switch (currCh) {
            case ' ':
                continue;
            case '(':
                *root = calloc(1, sizeof(Node));
                if (*root == NULL) {
                    return 1;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (*root == NULL) {
                    return 1;
                }
                (*root)->op = currCh;
                (*root)->isOp = true;
                Error err = 0;
                err = buildTree(&(*root)->left, in);
                if (err != 0) {
                    return err;
                }
                err = buildTree(&(*root)->right, in);
                if (err != 0) {
                    return err;
                }
                break;
            case ')':
                return 0;
            default: //if number
                ungetc(currCh, in);
                *root = calloc(1, sizeof(Node));
                if (*root == NULL) {
                    return 1;
                }
                (*root)->isOp = false;
                int number = 0;
                fscanf(in, "%d", &number);
                (*root)->value = number;
                return 0;
        }
    }
}

void printTree(Node *root) {
    if (root == NULL) {
        return;
    }
    if (!root->isOp) {
        printf("%d ", root->value);
    } else {
        printf("( %c ", root->op);
        printTree(root->left);
        printTree(root->right);
        printf(") ");
    }
}

int evaluateTree(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (!root->isOp) {
        return root->value;
    }
    int left = evaluateTree(root->left);
    int right = evaluateTree(root->right);
    switch (root->op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            return 0;
    }
}

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    if (root->isOp) {
        freeTree(root->left);
        freeTree(root->right);
    }
    free(root);
}