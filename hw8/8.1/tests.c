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
    root = addNode(root, "key1", "string1");
    root = addNode(root, "key2", "string 2");
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
    root = addNode(root, "555", "string1");
    root = addNode(root, "666", "string2");
    root = addNode(root, "555", "string");
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
    root = addNode(root, "555", "string1");
    root = addNode(root, "666", "string2");
    root = deleteNode(root, "555");
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
    root = addNode(root, "1", "a");
    root = addNode(root, "2", "b");
    root = addNode(root, "3", "c");
    root = addNode(root, "4", "d");
    root = addNode(root, "5", "e");
    root = addNode(root, "6", "f");
    root = addNode(root, "7", "g");
    root = addNode(root, "8", "h");
    bool result = height(root) <= 4; // [log_2(8)] + 1
    if (!result) {
        printf("testHeight failed\n");
    }
    return result;
}

bool isPassed() {
    return testAddAndFind() &&
           testChange() &&
           testDel() &&
           testHeight();
}
