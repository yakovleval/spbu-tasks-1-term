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

bool isBracket(const char symbol) {
    return symbol == '(' || symbol == ')' ||
           symbol == '[' || symbol == ']' ||
           symbol == '{' || symbol == '}' ||
           symbol == '<' || symbol == '>';
}

bool areBracketsBalanced(const char *string) {
    char *stack = NULL;
    int topIndex = 0; // points to first free index
    for (int i = 0; i < strlen(string); i++) {
//        if (!isBracket(string[i])) {
//            continue;
//        }
        switch (string[i]) {
            case '(':
            case '[':
            case '{':
            case '<':
                stack[topIndex] = string[i];
                topIndex++;
                break;
            case ')':
            case ']':
            case '}':
            case '>':
                if (topIndex == 0 ||
                    !isSameType(stack[topIndex - 1], string[i])) {
                    free(stack);
                    return false;
                }
                topIndex--;
                break;
            default:
                continue;
        }
    }
    free(stack);
    return topIndex == 0;
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    printf("Hello, World!\n");
    return 0;
}
