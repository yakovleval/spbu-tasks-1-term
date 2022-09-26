#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 256

void evalPiFunction(const char *string, unsigned length, int *piFunction) {
    piFunction[0] = 0;
    for (int i = 1; i < length; i++) {
        int j = piFunction[i - 1];
        while (j > 0 && string[i] != string[j]) {
            j = piFunction[j - 1];
        }
        if (string[i] == string[j]) {
            j++;
        }
        piFunction[i] = j;
    }
}

int occurencesNumber(const char *substring, const char *string) {
    // building "substring\0string" for p-function
    char resultString[MAX_LENGTH * 2 + 2] = {0};
    strcpy(resultString, substring);
    strcat(resultString, "$");
    strcat(resultString, string);

    unsigned length = strlen(resultString);
    resultString[strlen(substring)] = '\0';

    int piFunction[MAX_LENGTH * 2 + 2] = {0};
    evalPiFunction(resultString, length, piFunction);
    int count = 0;
    for (unsigned i = strlen(substring) + 1; i < length; i++) {
        if (piFunction[i] == strlen(substring)) {
            count++;
        }
    }
    return count;
}

int main() {
    char string[MAX_LENGTH + 1] = {0};
    printf("введите исходную строку: \n");
    scanf("%255s", string);
    char substring[MAX_LENGTH + 1] = {0};
    printf("введите подстроку, которые нужно найти: \n");
    scanf("%255s", substring);

    printf("количество данных подстрок в исходной строке равно %d\n",
           occurencesNumber(substring, string));
    return 0;
}
