#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "dijkstra.h"

int main() {
    setlocale(LC_ALL, "RU-ru");
    FILE *in = fopen("file.txt", "r");
    int vertecies, edges;
    fscanf(in, "%d%d", &vertecies, &edges);
    //verticies' numeration from 0
    int **graph = calloc(vertecies, sizeof(int*));
    for (int i = 0; i < vertecies; i++) {
        graph[i] = calloc(vertecies, sizeof(int));
        for (int j = 0; j < vertecies; j++)
            graph[i][j] = -1;
    }
    for (int i = 0; i < edges; i++) {
        int left, right, weight;
        fscanf(in, "%d%d%d", &left, &right, &weight);
        graph[left][right] = graph[right][left] = weight;
    }
    int capitalsNumber;
    fscanf(in, "%d", &capitalsNumber);
    int *capitals = calloc(capitalsNumber, sizeof(int));
    for (int i = 0; i < capitalsNumber; i++) {
        fscanf(in, "%d", &capitals[i]);
    }
    fclose(in);
    int *answer = calloc(vertecies, sizeof(int));
    for (int i = 0; i < vertecies; i++)
        answer[i] = -1;

    for (int i = 0; i < capitalsNumber; i++) {
        dijkstra(graph, capitals[i], answer, vertecies, vertecies / capitalsNumber);
    }
    for (int i = 0; i < vertecies % capitalsNumber; i++) {
        dijkstra(graph, capitals[i], answer, vertecies, 1);
    }

    for (int i = 0; i < capitalsNumber; i++) {
        printf("%d: ", capitals[i]);
        for (int j = 0; j < vertecies; j++) {
            if (answer[j] == capitals[i])
                printf("%d ", j);
        }
        printf("\n");
    }

    free(answer);
    free(capitals);
    for (int i = 0; i < vertecies; i++) {
        free(graph[vertecies]);
    }
    free(graph);
    return 0;
}
