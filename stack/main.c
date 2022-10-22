#include <stdio.h>
#include "stack.h"
#include <locale.h>

bool testPush() {
    Node *head = NULL;
    int charToPush = 'a';
    int errorCode = push(&head, charToPush);
    if (errorCode != 0) {
        free(head);
        return false;
    }
    if (head->value == charToPush) {
        free(head);
        return true;
    }
    free(head);
    return false;
}

bool testPop() {
    Node *head = NULL;
    int charToPush = 'a';
    int errorCode = push(&head, charToPush);
    if (errorCode != 0) {
        free(head);
        return false;
    }
    int value = 0;
    errorCode = pop(&head, &value);
    if (errorCode != 0) {
        free(head);
        return false;
    }

    free(head);
    return value == charToPush;
}

bool testDeleteAll() {
    Node *head = NULL;
    int charToPush = 'a';
    for (int i = 0; i < 10; ++i) {
        int errorCode = push(&head, charToPush);
        if (errorCode != 0) {
            deleteAll(&head);
            return false;
        }
    }
    int errorCode = deleteAll(&head);
    if (errorCode != 0) {
        return false;
    }
    return isEmpty(head);
}

bool testDeleteAllOneElement() {
    Node *head = NULL;
    int charToPush = 'a';
    int errorCode = push(&head, charToPush);
    if (errorCode != 0) {
        free(head);
        return false;
    }
    errorCode = deleteAll(&head);
    if (errorCode != 0) {
        return false;
    }
    return head == NULL;
}

bool testIsEmpty() {
    Node *head = NULL;
    return isEmpty(head);
}

bool testTop() {
    Node *head = NULL;
    int charToPush = 'a';
    push(&head, charToPush);
    int topChar = 0;
    int error = top(head, &topChar);
    return error == 0 && charToPush == topChar;
}

bool testArbitrary() {
    Node *head = NULL;
    push(&head, 'a');
    push(&head, 'b');
    push(&head, 'c');
    push(&head, 'd');
    int popedChar = 0;
    pop(&head, &popedChar);
    if (popedChar != 'd') {
        deleteAll(&head);
        return false;
    }
    pop(&head, &popedChar);
    if (popedChar != 'c') {
        deleteAll(&head);
        return false;
    }
    push(&head, 'e');
    pop(&head, &popedChar);
    if (popedChar != 'e') {
        deleteAll(&head);
        return false;
    }
    deleteAll(&head);
    return true;
}

bool isPassed() {
    return testPush() &&
           testPop() &&
           testIsEmpty() &&
           testDeleteAll() &&
           testDeleteAllOneElement() &&
           testTop() &&
           testArbitrary();
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    printf("тесты пройдены\n");
    return 0;
}
