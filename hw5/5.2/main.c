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

bool areBracketsBalanced(const char *string) {
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
                    return false;
                }
                break;
            case ')':
            case ']':
            case '}':
            case '>':
                if (isEmpty(stack)) {
                    return false;
                }
                char topBracket = 0;
                error = pop(&stack, &topBracket);
                if (error != 0) {
                    deleteAll(&stack);
                    return false;
                }
                if (!isSameType(topBracket, string[i])) {
                    deleteAll(&stack);
                    return false;
                }
                break;
            default:
                continue;
        }
    }
    bool empty = isEmpty(stack);
    deleteAll(&stack);
    return empty;
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    char string[256] = {0};
    printf("введите строку: \n");
    scanf("%255s", string);
    printf(areBracketsBalanced(string) ?
           "скобки сбалансированы\n" :
           "скобки несбалансированы\n");
    return 0;
}
