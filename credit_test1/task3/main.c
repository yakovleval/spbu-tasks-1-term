#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define BUFFER_SIZE 257

bool isLetter(char ch) {
    return 'a' <= ch && ch <= 'z' ||
           'A' <= ch && ch <= 'Z';
}

bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

bool isCorrect(const char *string, int size) {
    int state = 0;
    for (int i = 0; i < size; i++) {
        char current = string[i];
        switch (state) {
            case 0:
                if (isLetter(current))
                    state = 1;
                else
                    return false;
                break;
            case 1:
                if (!isLetter(current) && !isDigit(current) && current != '_')
                    return false;
                break;
        }
    }
    return true;
}

int main() {
    printf("enter the string:\n");
    char buffer[BUFFER_SIZE];
    scanf("%256s", buffer);
    if (isCorrect(buffer, strlen(buffer))) {
        printf("string is correct\n");
    }
    else
        printf("string is incorrect\n");
    return 0;
}
