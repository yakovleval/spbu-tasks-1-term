#include "stack.h"


int push(Node **Last, char value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        return 1;
    }
    newNode->value = value;
    newNode->next = (*Last);
    (*Last) = newNode;
    return 0;
}

int pop(Node **head, char *value) {
    if (head == NULL) {
        return 1;
    }
    Node *previous = (*head);
    *value = (*head)->value;
    (*head) = (*head)->next;
    free(previous);
    return 0;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

int deleteAll(Node **head) {
    while (!isEmpty(*head)) {
        char value = 0;
        int errorCode = pop(head, &value);
        if (errorCode != 0) {
            return errorCode;
        }
    }
    return 0;
}
