#include <stdio.h>
#include <locale.h>
#include "qsort.h"

int mostFrequent(int *array, const int size) {
    memcpy(array, array, size * sizeof(int));
    quickSort(array, 0, size - 1);
    int answer = array[0];
    int current = answer;
    int maxCount = 1;
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (array[i] == current) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                answer = array[i - 1];
            }
            count = 1;
            current = array[i];
        }
    }
    if (count > maxCount) {
        maxCount = count;
        answer = array[size - 1];
        count = 1;
    }
    return answer;
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("ошибка открытия файла\n");
        return 0;
    }
    int size = 0;
    int tmp = 0;
    while (fscanf(file, "%d", &tmp) == 1) {
        size++;
    }
    fseek(file, 0L, SEEK_SET);
    if (size == 0) {
        printf("файл пуст\n");
        fclose(file);
        return 0;
    }
    int *array = (int *) calloc(size, sizeof(int));
    if (array == NULL) {
        printf("ошибка выделения памяти\n");
        fclose(file);
        return 0;
    }
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);

    printf("самый частый элемент в массиве: %d\n", mostFrequent(array, size));
    free(array);
    return 0;
}
