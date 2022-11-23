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
    Date maxDate = {0};
    Date curDate = {0};
    while (fscanf(in, "%d.%d.%d", &curDate.day, &curDate.month, &curDate.year) == 3) {
        if (cmpDates(maxDate, curDate) < 0) {
            maxDate.day = curDate.day;
            maxDate.month = curDate.month;
            maxDate.year = curDate.year;
        }
    }
    fclose(in);
    printf("%02d.%02d.%d\n", maxDate.day, maxDate.month, maxDate.year);
    return 0;
}
