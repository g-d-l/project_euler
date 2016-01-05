#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000000
#define FRAC 0.99
#define PM 524287

typedef struct person {
    int rank;
    int size;
    struct person* parent;
} person;

void makeset(person* x);
person* find(person* x);
person* link(person* x, person* y);
void make_union(person* x, person* y);
int get_size(person* x);
int get_Sk(long long k, long long* fib);

int main(void) {
    person* system = malloc(sizeof(person) * N);
    for (int i = 0; i < N; i++)
        makeset(&system[i]);
    
    long long* fib = malloc(sizeof(long long) * 56);
    
    int end = ceil((float) FRAC * N);
    int count = 0;
    int misdials = 0;
    while (get_size(&system[PM]) < end) {
        int caller = get_Sk(++count, fib);
        int called = get_Sk(++count, fib);
        if (caller != called)
            make_union(&system[called], &system[caller]);
        else
            misdials++;
    }
    printf("%d\n", count / 2 - misdials);
    free(fib);
    free(system);
}

void makeset(person* x) {
    x->parent = x;
    x->rank = 0;
    x->size = 1;
    return;
}

person* find(person* x) {
    if (x != x->parent)
        x->parent = find(x->parent);
    return x->parent;
}

person* link(person* x, person* y) {
    if (x->rank > y->rank) {
        person* copy = x;
        x = y;
        y = copy;
    }
    if (x->rank == y->rank)
        y->rank++;
    x->parent = y;
    y->size += x->size;
    return y;
}

void make_union(person* x, person* y) {
    person* xp = find(x);
    person* yp = find(y);
    if (xp != yp)
        link(xp, yp);
    return;
}

int get_size(person* x) {
    return find(x)->size;
}

int get_Sk(long long k, long long* fib) {
    if (k <= 55) {
        fib[k] = ((long long) 100003 - (long long) 200003 * k + (long long) 300007 * k * k * k) % N;
        return fib[k];
    }
    else {
        int s24 = fib[(k - 24) % 56];
        int s55 = fib[(k - 55) % 56];
        fib[k % 56] = (s24 + s55) % N;
        return fib[k % 56];
    }
}
