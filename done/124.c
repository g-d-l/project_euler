#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100000

typedef struct slot {
    int n;
    long long radn; 
} slot;

int compare(const void* a, const void* b);

int main(void) {
    slot* array = malloc(sizeof(slot) * (LIMIT + 1));
    for (int i = 1; i <= LIMIT; ++i) {
        array[i].radn = 1;
        array[i].n = i;
    }
        
    for (int i = 2; i <= LIMIT; i++) {
        if (array[i].radn == 1) {
            for (int j = i; j <= LIMIT; j+= i)
                array[j].radn *= i;
        }
    }
    qsort(&array[1], LIMIT, sizeof(slot), compare);
    printf("%d\n", array[10000].n);
    free(array);
}

int compare(const void* a, const void* b) {
    slot* a_ptr = (slot*) a;
    slot* b_ptr = (slot*) b;
    if (a_ptr->radn != b_ptr->radn)
        return (a_ptr->radn > b_ptr->radn) ? 1 : -1;
    else
        return (a_ptr->n > b_ptr->n) ? 1 : -1;
}
