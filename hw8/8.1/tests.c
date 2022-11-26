#include <string.h>
#include <stdio.h>
#include "tests.h"
#include "tree.h"

int height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->leftChild);
    int rightHeight = height(root->rightChild);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool testAddAndFind() {
    Node *root = NULL;
    root = add(root, "key1", "string1");
    root = add(root, "key2", "string 2");
    const bool result = strcmp(findValue(root, "key1"), "string1") == 0 &&
                        strcmp(findValue(root, "key2"), "string 2") == 0 &&
                        findValue(root, "777") == NULL;
    freeTree(root);
    if (!result) {
        printf("testAddAndFind failed\n");
    }
    return result;
}

bool testChange() {
    Node *root = NULL;
    root = add(root, "555", "string1");
    root = add(root, "666", "string2");
    root = add(root, "555", "string");
    const bool result = strcmp(findValue(root, "555"), "string") == 0 &&
                        strcmp(findValue(root, "666"), "string2") == 0;
    freeTree(root);
    if (!result) {
        printf("testChange failed\n");
    }
    return result;
}

bool testDel() {
    Node *root = NULL;
    root = add(root, "555", "string1");
    root = add(root, "666", "string2");
    root = delete(root, "555");
    const bool result = findValue(root, "555") == NULL &&
                        strcmp(findValue(root, "666"), "string2") == 0;
    freeTree(root);
    if (!result) {
        printf("testDel failed\n");
    }
    return result;
}

bool testHeight() {
    Node *root = NULL;
    root = add(root, "1", "a");
    root = add(root, "2", "b");
    root = add(root, "3", "c");
    root = add(root, "4", "d");
    root = add(root, "5", "e");
    root = add(root, "6", "f");
    root = add(root, "7", "g");
    root = add(root, "8", "h");
    bool result = height(root) <= 4; // [log_2(8)] + 1
    if (!result) {
        printf("testHeight failed\n");
    }
    return result;
}

int checkBalances(Node *node, bool *areBalancesCorrect) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = checkBalances(node->leftChild, areBalancesCorrect);
    int rightHeight = checkBalances(node->rightChild, areBalancesCorrect);
    *areBalancesCorrect &= rightHeight - leftHeight == node->balance;
    *areBalancesCorrect &= -1 <= node->balance && node->balance <= 1;
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool testBalances() {
    Node *root = NULL;
    root = add(root, "1", "a");
    root = add(root, "2", "b");
    root = add(root, "3", "c");
    root = add(root, "4", "d");
    root = add(root, "5", "e");
    root = add(root, "6", "f");
    root = add(root, "7", "g");
    root = add(root, "8", "h");
    bool result = true;
    checkBalances(root, &result);
    root = delete(root, "4");
    root = delete(root, "5");
    root = delete(root, "6");
    checkBalances(root, &result);
    freeTree(root);
    if (!result) {
        printf("testBalances failed\n");
    }
    return result;
}

bool isPassed() {
    return testAddAndFind() &&
           testChange() &&
           testDel() &&
           testHeight() &&
           testBalances();
}
