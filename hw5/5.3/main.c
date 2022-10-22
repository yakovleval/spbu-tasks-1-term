#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "../../stack/stack.h"

#define MAX_BUF 256

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

bool isOp(char c) {
    return c == '+' ||
           c == '-' ||
           c == '*' ||
           c == '/';
}

bool isHigherThan(const char leftOp, const char rightOp) {
    return leftOp == '*' ||
           leftOp == '/' ||
           rightOp == '+' ||
           rightOp == '-';
}

void addChar(char *output, int *index, const char ch) {
    output[(*index)++] = ch;
}

int sortingStation(const char *input, const int inputSize, char *output) {
    Node *stack = NULL;
    int outputPointer = 0;
    int error = 0;
    for (int i = 0; i < inputSize; i++) {
        if (isDigit(input[i])) {
            addChar(output, &outputPointer, input[i]);
            continue;
        }
        if (input[i] == ' ') {
            continue;
        }
        switch (input[i]) {
            case '*':
            case '/':
            case '+':
            case '-': {
                char topChar = 0;
                if (!isEmpty(stack)) {
                    error = top(stack, &topChar);
                    if (error != 0) {
                        deleteAll(&stack);
                        return error;
                    }
                    while (!isEmpty(stack) && isOp(topChar) && isHigherThan(topChar, input[i])) {
                        addChar(output, &outputPointer, topChar);
                        error = pop(&stack, &topChar);
                        if (error != 0) {
                            deleteAll(&stack);
                            return error;
                        }
                        if (!isEmpty(stack)) {
                            error = top(stack, &topChar);
                            if (error != 0) {
                                deleteAll(&stack);
                                return error;
                            }
                        }
                    }
                }
                error = push(&stack, input[i]);
                if (error != 0) {
                    deleteAll(&stack);
                    return error;
                }
                break;
            }
            case '(':
                error = push(&stack, input[i]);
                if (error != 0) {
                    deleteAll(&stack);
                    return error;
                }
                break;
            case ')': {
                if (isEmpty(stack)) {
                    deleteAll(&stack);
                    return 1;
                }
                char topChar = 0;
                error = top(stack, &topChar);
                if (error != 0) {
                    deleteAll(&stack);
                    return error;
                }
                while (!isEmpty(stack) && isOp(topChar)) {
                    addChar(output, &outputPointer, topChar);
                    error = pop(&stack, &topChar);
                    if (error != 0) {
                        deleteAll(&stack);
                        return error;
                    }
                    error = top(stack, &topChar);
                    if (error != 0) {
                        deleteAll(&stack);
                        return error;
                    }
                }
                if (isEmpty(stack)) {
                    deleteAll(&stack);
                    return 1;
                }
                error = pop(&stack, &topChar);
                if (error != 0) {
                    deleteAll(&stack);
                    return error;
                }
                break;
            }
            default:
                deleteAll(&stack);
                return 1;
        }
    }
    while (!isEmpty(stack)) {
        char topChar = 0;
        error = pop(&stack, &topChar);
        if (error != 0 || !isOp(topChar)) {
            deleteAll(&stack);
            return error;
        }
        addChar(output, &outputPointer, topChar);
    }
    addChar(output, &outputPointer, '\0');
    deleteAll(&stack);
    return 0;
}

bool isPassed() {
    const char *testCases[] = {"","(1+1)*2", "1", "3-2-1", "3+6*(3-2)", "(1+2)/(3-4)*((5*6)-(7*8))"};
    const char *expected[] = {"", "11+2*", "1", "32-1-", "3632-*+", "12+34-/56*78*-*"};
    char *polishNotation[MAX_BUF];
    bool result = true;
    for (int i = 0; i < sizeof(testCases) / sizeof(const char*); i++) {
        sortingStation(testCases[i], (int) strlen(testCases[i]), (char *) polishNotation);
        result &= strcmp((const char *) polishNotation, expected[i]) == 0;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    printf("тесты пройдены\n");
    printf("введите выражение:\n");
    char input[MAX_BUF], output[MAX_BUF];
    scanf("%255s", input);
    int error = sortingStation(input, (int) strlen(input), output);
    if (error != 0) {
        printf("ошибка\n");
        return 0;
    }
    printf("результат:\n");
    printf("%s", output);
    return 0;
}
