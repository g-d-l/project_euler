#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define TARGET 5

typedef struct node {
    struct node* prev;
    struct node* next;
    long long sorted;
    long long smallest;
    int count;
} node;

long long cube(long base);
long long sort_permutation(long long a);
void insert(node* init, long long value, long long sorted);
void freer(node* init);
long long check(node* init);

int main(void) {    
    bool done = false;
    int places = 2;
    long base = 3;
    while (!done) {
        node* start = malloc(sizeof(node));
        start->next = malloc(sizeof(node));
        start->next->next = NULL;
        start->next->prev = start;
        start->next->sorted = 0;
    
        long long value = cube(base);
        
        while (value <= powl(10., places)) {
            if (base == 345) {
                ;
            }
            else if (base == 384) {
                ;
            }
            else if (base == 405){
                ;
            }
            long long sorted = sort_permutation(value);
             insert(start->next, value, sorted);
             base++;
             value = cube(base); 
        }
        
        long long min = check(start->next);  
        freer(start);      
        if (min < powl(2., 61.)) {
            printf("%lld\n", min);
            done = true;
        }
        else {
            places++;
        }
        
    }
}


long long cube(long base) {
    return (long long) base * base * base;
}

long long sort_permutation(long long a) {
    int length = log10(a) + 1;
    bool sorted = false;
    int array[length];
    for (int i = length - 1; i >= 0; i--) {
        array[i] = a % 10;
        a = (a - array[i]) / 10;
    }
    
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < length - 1; i++) {
            if (array[i] < array[i + 1]) {
                sorted = false;
                int copy = array[i];
                array[i] = array[i + 1];
                array[i + 1] = copy;
            }
        }
    }
    long long result = 0;
    for (int i = 0; i < length; i++) {
        result = 10 * result + array[i];
    }
    return result;
}

void insert(node* init, long long value, long long sorted) {
    if (sorted > init->sorted) {
        node* new = malloc(sizeof(node));
        new->sorted = sorted;
        new->smallest = value;
        new->count = 1;
        new->next = init;
        new->prev = init->prev;
        if (init->prev != NULL)
            init->prev->next = new;
        init->prev = new;
    }
    else if (sorted == init->sorted)
        init->count++;
    else {
        if (init->next != NULL)
            return insert(init->next, value, sorted);
        else {
            node* new = malloc(sizeof(node));
            new->sorted = sorted;
            new->smallest = value;
            new->count = 1;
            new->next = NULL;
            new->prev = init;
            init->next = new;
        }
    }
}

void freer(node* init) {
    if (init != NULL) {
        free(init->next);
        free(init);
    }
}

long long check(node* init) {
    long long min = powl(2., 62.);
    while (init != NULL) {
        if (init->count == TARGET) {
            if (init->smallest < min) {
                min = init->smallest;
            }
        }
    init = init->next;
    }
    return min;
}
