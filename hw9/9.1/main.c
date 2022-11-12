#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "table.h"
#include "test.h"
#define MAX_BUFFER 256

int main() {
    setlocale(LC_ALL, "RU-ru");
    if (!isPassed()) {
        printf("тесты не пройдены\n");
        return 0;
    }
    FILE *in = fopen("file.txt", "r");
    if (in == NULL) {
        printf("ошибка открытия файла");
        return 0;
    }
    char buffer[MAX_BUFFER];
    Table *table = calloc(1, sizeof(Table));
    while (fscanf(in, "%255s", buffer) == 1) {
        add(table, buffer);
    }
    fclose(in);

    printf("частоты слов:\n");
    printTable(table);
    printf("коэффициент загрузки: %f\n", load(table));
    printf("средняя длина списка: %f\n", averageLen(table));

    freeTable(table);
    return 0;
}
