#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 40

typedef struct edge {
    int u;
    int v;
    int weight;
} edge;

typedef struct vertex {
    struct vertex* parent;
    int rank;
    int tree_size;
    int tree_weight;
} vertex;

void make_set(vertex* x);
vertex* find(vertex* x);
vertex* link(vertex* x, vertex* y, int weight);
void make_union(vertex* x, vertex* y, int weight);
int get_size(vertex* x);
int get_weight(vertex* x);
int edge_cmp(const void* x, const void* y);

int main(void) {
    FILE* source = fopen("107_numbers.txt", "r");
    if (source == NULL)
        return 1;
        
    vertex* trees = malloc(sizeof(vertex) * V);
    for (int i = 0; i < V; i++)
        make_set(&trees[i]);
    
    edge* edges = malloc(sizeof(edge) * ((V * (V - 1)) / 2));
    
    int orig_weight = 0;
    int edge_count = 0;
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            bool done = false;
            int weight = 0;
            while (!done) {
                char c = fgetc(source);
                if (c == '-') {
                    done = true;
                    fseek(source, 1, SEEK_CUR);
                }
                else if (c == ',' || c == '\n') {
                    done = true;
                    if (j > i) {
                        edges[edge_count].u = i;
                        edges[edge_count].v = j;
                        edges[edge_count].weight = weight;
                        edge_count++;
                        orig_weight += weight;
                    }
                }
                else
                    weight = 10 * weight + c - '0';
            }
        }
    }
    
    qsort(edges, edge_count, sizeof(edge), edge_cmp);
    int current_edge = 0;
    
    while (1) {
        make_union(&trees[edges[current_edge].u], 
            &trees[edges[current_edge].v], edges[current_edge].weight);
        current_edge++;
        if (get_size(&trees[edges[current_edge].u]) == V)
            break;
    }
    
    printf("%d\n", orig_weight - get_weight(&trees[edges[current_edge].u]));
}

void make_set(vertex* x) {
    x->parent = x;
    x->rank = 0;
    x->tree_size = 1;
    x->tree_weight = 0;
    return;
}

vertex* find(vertex* x) {
    if (x != x->parent)
        x->parent = find(x->parent);
    return x->parent;
}

vertex* link(vertex* x, vertex* y, int weight) {
    if (x->rank > y->rank) {
        vertex* copy = x;
        x = y;
        y = copy;
    }
    if (x->rank == y->rank)
        y->rank++;
    x->parent = y;
    y->tree_size += x->tree_size;
    y->tree_weight += x->tree_weight + weight;
    return y;
}

void make_union(vertex* x, vertex* y, int weight) {
    vertex* xp = find(x);
    vertex* yp = find(y);
    if (xp != yp)
        link(xp, yp, weight);
    return;
}

int get_size(vertex* x) {
    return find(x)->tree_size;
}

int get_weight(vertex* x) {
    return find(x)->tree_weight;
}

int edge_cmp(const void* x, const void* y) {
    edge* x1 = (edge*) x;
    edge* y1 = (edge*) y;
    if (x1->weight < y1->weight)
        return -1;
    else if (x1->weight == y1->weight)
        return 0;
    else
        return 1;
}
