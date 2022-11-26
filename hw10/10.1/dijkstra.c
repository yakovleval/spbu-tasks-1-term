#include <malloc.h>
#include "dijkstra.h"

int cmp(int dist1, int dist2) {
    if (dist1 == dist2)
        return 0;
    if (dist2 == -1)
        return -1;
    if (dist1 == -1)
        return 1;
    return dist1 - dist2;
}

void dijkstra(int **graph, int capital, int *answer, int vertecies, int neighbours) {
    int *dist = calloc(vertecies, sizeof(int));
    for (int i = 0; i < vertecies; i++)
        dist[i] = -1;
    dist[capital] = 0;
    for (int i = 0; i < neighbours; i++) {
        int nearestVertex = -1;
        for (int j = 0; j < vertecies; j++) {
            if (answer[j] == -1 && (nearestVertex == -1 || cmp(dist[j], dist[nearestVertex]) < 0))
                nearestVertex = j;
        }
        answer[nearestVertex] = capital;
        for (int j = 0; j < vertecies; j++) {
            if (graph[nearestVertex][j] == -1)
                continue;
            if (dist[j] == -1 || dist[nearestVertex] + graph[nearestVertex][j] < dist[j])
                dist[j] = dist[nearestVertex] + graph[nearestVertex][j];
        }
    }

    free(dist);
}
