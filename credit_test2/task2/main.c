#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

enum Direction {
    LINE, COLUMN
};

enum Extremum {
    MIN, MAX
};

int findExtremum(int *matrix, int height, int width, int vectorIndex, enum Direction direction, enum Extremum extremum) {
    int size = direction == LINE ? width : height;
    int result = matrix[direction == LINE ? vectorIndex * height : vectorIndex];
    for (int i = 0; i < size; i++) {
        int current = matrix[direction == LINE ? vectorIndex * height + i : i * height + vectorIndex];
        if (extremum == MIN)
            result = current < result ? current : result;
        else
            result = current > result ? current : result;
    }
    return result;
}


bool isSaddle(int *matrix, int height, int width, int lineIndex, int columnIndex) {
    int minLine = findExtremum(matrix, height, width, lineIndex, LINE, MIN);
    int maxLine = findExtremum(matrix, height, width, lineIndex, LINE, MAX);
    int minColumn = findExtremum(matrix, height, width, columnIndex, COLUMN, MIN);
    int maxColumn = findExtremum(matrix, height, width, columnIndex, COLUMN, MAX);
    int element = matrix[lineIndex * height + columnIndex];
    return element == minLine && element == maxColumn ||
           element == maxLine && element == minColumn;
}

int main() {
    FILE *in = fopen("matrix.txt", "r");
    if (in == NULL) {
        printf("error when opening file\n");
        return 0;
    }
    int height, width;
    if (fscanf(in, "%d%d", &height, &width) != 2 || height < 0 || width < 0) {
        printf("file format error\n");
        fclose(in);
        return 0;
    }
    int *matrix = calloc(height * width, sizeof(int));
    if (matrix == NULL) {
        printf("error when allocating memory\n");
        fclose(in);
        return 0;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value;
            if (fscanf(in, "%d", &value) != 1) {
                printf("file format error\n");
                free(matrix);
                fclose(in);
                return 0;
            }
            matrix[i * height + j] = value;
        }
    }
    int extraValue;
    if (fscanf(in, "%d", &extraValue) == 1) {
        printf("file format error\n");
        free(matrix);
        fclose(in);
        return 0;
    }
    printf("saddle points:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (isSaddle(matrix, height, width, i, j)) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
    return 0;
}
