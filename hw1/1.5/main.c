#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
    char *stack = calloc(strlen(string) + 1, sizeof(char));
    int topIndex = 0; // points to first free index
    for (int i = 0; i < strlen(string); i++) {
        if (!isBracket(string[i])) {
            continue;
        }
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
        }
    }
    free(stack);
    return topIndex == 0;
}

int main() {
    char string[256] = {0};
    printf("введите строку: \n");
    scanf("%255s", string);
    printf(areBracketsBalanced(string) ?
    "скобки сбалансированы\n" :
    "скобки несбалансированы\n");
    return 0;
}
