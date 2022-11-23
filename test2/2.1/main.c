#include <stdio.h>
#include <locale.h>
#include "date.h"


int main() {
    setlocale(LC_ALL, "RU-ru");
    FILE *in = fopen("file.txt", "r");
    if (in == NULL) {
        printf("ошибка открытия файла\n");
        return 0;
    }
    Date maxDate = findMaxDate(in);
    fclose(in);
    printf("%02d.%02d.%d\n", maxDate.day, maxDate.month, maxDate.year);
    return 0;
}
