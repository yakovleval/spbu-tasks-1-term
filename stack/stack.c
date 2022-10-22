#include "stack.h"


int push(Node **head, const char value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL || head == NULL) {
        return 1;
    }
    newNode->value = value;
    newNode->next = (*head);
    (*head) = newNode;
    return 0;
}

int pop(Node **head, char *value) {
    if (head == NULL || *head == NULL) {
        return 1;
    }
    Node *previous = (*head);
    *value = (*head)->value;
    (*head) = (*head)->next;
    free(previous);
    return 0;
}

int top(const Node * const head, char *value) {
    if (head == NULL) {
        return 1;
    }
    *value = head->value;
    return 0;
}

bool isEmpty(const Node * const head) {
    return head == NULL;
}

int deleteAll(Node **head) {
    if (head == NULL) {
        return 1;
    }
    while (!isEmpty(*head)) {
        char value = 0;
        int errorCode = pop(head, &value);
        if (errorCode != 0) {
            return errorCode;
        }
    }
    return 0;
}
