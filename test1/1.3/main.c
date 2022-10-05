#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int main() {
    setlocale(LC_ALL, "RU-ru");
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("ошибка открытия файла\n");
        return 0;
    }
    bool isComment = false;
    int intChar = 0;
    while ((intChar = fgetc(file)) != EOF) {
        char character = (char) intChar;
        if (character == ';') {
            isComment = true;
        }
        if (character == '\n' && isComment) {
            isComment = false;
            printf("\n");
        }
        if (isComment) {
            printf("%c", character);
        }
    }
    fclose(file);
    return 0;
}
