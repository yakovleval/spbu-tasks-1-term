#include <stdio.h>
#include <locale.h>
#include "../../stack/stack.h"
#define MAX_BUF 256

bool isOp(const char ch) {
    return  ch == '+' ||
            ch == '-' ||
            ch == '*' ||
            ch == '/';
}

int evaluateOp(const int left, const int right, const char op) {
    switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }
}

int evaluateExpr(const char *input, const int size, int *answer) {
    Node *stack = NULL;
    int error = 0;
    for (int i = 0; i < size; i++) {
        if ('0' <= input[i] && input[i] <= '9') {
            error = push(&stack, input[i] - '0');
            if (error != 0) {
                deleteAll(&stack);
                return error;
            }
        } else if (isOp(input[i])) {
            int left = 0, right = 0;
            if (isEmpty(stack)) {
                deleteAll(&stack);
                return 1;
            }
            error = pop(&stack, &right);
            if (error != 0) {
                deleteAll(&stack);
                return error;
            }
            if (isEmpty(stack)) {
                deleteAll(&stack);
                return 1;
            }
            error = pop(&stack, &left);
            if (error != 0) {
                deleteAll(&stack);
                return error;
            }
            error = push(&stack, evaluateOp(left, right, input[i]));
            if (error != 0) {
                deleteAll(&stack);
                return error;
            }
        }
    }
    if (isEmpty(stack)) {
        deleteAll(&stack);
        return 1;
    }
    error = pop(&stack, answer);
    if (error != 0) {
        deleteAll(&stack);
        return error;
    }
    return 0;
}

bool isPassed() {
    const char *testCases[] = {"0", "96-12+*", "12+", "84/2/"};
    const int expected[] = {0, 9, 3, 1};
    bool result = true;
    for (int i = 0; i < sizeof(testCases) / sizeof(const char*); i++) {
        int answer = 0;
        int error = evaluateExpr(testCases[i], strlen(testCases[i]), &answer);
        if (error != 0 || answer != expected[i]) {
            return false;
        }
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
    char input[MAX_BUF];
    scanf("%255s", input);
    int answer = 0;
    int error = evaluateExpr(input, strlen(input), &answer);
    if (error != 0) {
        printf("ошибка\n");
        return 0;
    }
    printf("ответ: %d\n", answer);
    return 0;
}
