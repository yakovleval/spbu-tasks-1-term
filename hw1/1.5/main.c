#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSameType(const char leftBrace, const char rightBrace) {
    return leftBrace == '(' && rightBrace == ')' ||
    leftBrace == '[' && rightBrace == ']' ||
    leftBrace == '{' && rightBrace == '}' ||
    leftBrace == '<' && rightBrace == '>';
}

bool areBracketsBalanced(const char *brackets) {
    char stack[strlen(brackets) + 1];
    int topIndex = 0; // points to first free index
    for (int i = 0; i < strlen(brackets); i++) {
        switch (brackets[i]) {
            case '(':
            case '[':
            case '{':
            case '<':
                stack[topIndex] = brackets[i];
                topIndex++;
                break;
            case ')':
            case ']':
            case '}':
            case '>':
                if (topIndex == 0 ||
                    !isSameType(stack[topIndex - 1], brackets[i])) {
                    return false;
                }
                topIndex--;
                break;
            default:
                return false;
        }
    }
    return topIndex == 0;
}

int main() {
    char brackets[256] = {0};
    printf("введите последовательность из скобок (), [], {} или <>: \n");
    scanf("%255s", brackets);
    printf(areBracketsBalanced(brackets) ?
    "скобочная последовательность правильная\n" :
    "скобочная последовательность неправильная\n");
    return 0;
}
