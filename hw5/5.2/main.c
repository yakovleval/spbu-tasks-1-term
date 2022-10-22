#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include "../../stack/stack.h"

bool isSameType(const char leftBrace, const char rightBrace) {
    return leftBrace == '(' && rightBrace == ')' ||
           leftBrace == '[' && rightBrace == ']' ||
           leftBrace == '{' && rightBrace == '}' ||
           leftBrace == '<' && rightBrace == '>';
}

int areBracketsBalanced(const char *string, bool *result) {
    Node *stack = NULL;
    int error = 0;
    for (int i = 0; i < strlen(string); i++) {
        switch (string[i]) {
            case '(':
            case '[':
            case '{':
            case '<':
                error = push(&stack, string[i]);
                if (error != 0) {
                    deleteAll(&stack);
                    return error;
                }
                break;
            case ')':
            case ']':
            case '}':
            case '>':
                if (isEmpty(stack)) {
                    *result = false;
                    return 0;
                }
                char topBracket = 0;
                error = pop(&stack, &topBracket);
                if (error != 0) {
                    deleteAll(&stack);
                    return error;
                }
                if (!isSameType(topBracket, string[i])) {
                    deleteAll(&stack);
                    *result = false;
                }
                break;
            default:
                continue;
        }
    }
    bool empty = isEmpty(stack);
    deleteAll(&stack);
    *result = empty;
    return 0;
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    char string[256] = {0};
    printf("введите строку: \n");
    scanf("%255s", string);
    bool areBalanced = true;
    int error = areBracketsBalanced(string, &areBalanced);
    if (error != 0) {
        printf("ошибка\n");
        return 0;
    }
    printf(areBalanced ?
           "скобки сбалансированы\n" :
           "скобки несбалансированы\n");
    return 0;
}