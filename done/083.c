#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 80

typedef struct edge {
    int u;
    int v;
    int weight;
} edge;

void bellman_ford(int vertex_count, edge* edges, int edge_count, int source,
    int* distance, int* predecessor);

int main(void) {
    FILE* f = fopen("083_numbers.txt", "r");
    if (f == NULL)
        return -1;
    
    int vertex_count = N * N * 2;
    int edge_count = 0;
    edge* edges = malloc(sizeof(edge) * N * N * 6);
    int weight = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(f, "%d", &weight);
            fgetc(f);
            // upper right
            edges[edge_count].u = 2 * i * N + j;
            edges[edge_count].v = (2 * i + 1) * N + j;
            edges[edge_count].weight = weight;
            edge_count++;
            if (j > 0) {
                // upper left
                edges[edge_count].u = (2 * i + 1) * N + j - 1;
                edges[edge_count].v = (2 * i) * N + j;
                edges[edge_count].weight = weight;
                edge_count++;
                // left-right
                edges[edge_count].u = (2 * i + 1) * N + j;
                edges[edge_count].v = (2 * i + 1) * N + j - 1;
                edges[edge_count].weight = weight;
                edge_count++;
                if (i < N - 1) {
                    // bottom left
                    edges[edge_count].u = (2 * i + 1) * N + j - 1;
                    edges[edge_count].v = (2 * i + 2) * N + j;
                    edges[edge_count].weight = weight;
                    edge_count++;
                }
            }
            if (i < N - 1) {
                // up-down
                edges[edge_count].u = 2 * i * N + j;
                edges[edge_count].v = (2 * i + 2) * N + j;
                edges[edge_count].weight = weight;
                edge_count++;
                // bottom right
                edges[edge_count].u = (2 * i + 1) * N + j;
                edges[edge_count].v = (2 * i + 2) * N + j;
                edges[edge_count].weight = weight;
                edge_count++;
            }
        }
    }
    
    int* distance = malloc(sizeof(int) * vertex_count);
    int* predecessor = malloc(sizeof(int) * vertex_count);
    bellman_ford(vertex_count, edges, edge_count, 0, distance, predecessor);
    printf("%d\n", distance[2 * N * N - 1]);
    
}

void bellman_ford(int vertex_count, edge* edges, int edge_count, int source,
    int* distance, int* predecessor) {
    for (int i = 0; i < vertex_count; i++) {
        if (i == source)
            distance[i] = 0;
        else
            distance[i] = INT_MAX / 2;
        predecessor[i] = -1;
    }
    
    for (int i = 0; i < vertex_count - 1; i++) {
        for (int j = 0; j < edge_count; j++) {
            if (distance[edges[j].u] + edges[j].weight < distance[edges[j].v])
                distance[edges[j].v] = distance[edges[j].u] + edges[j].weight;
            if (distance[edges[j].v] + edges[j].weight < distance[edges[j].u])
                distance[edges[j].u] = distance[edges[j].v] + edges[j].weight;
        }
    }
}
