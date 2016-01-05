#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define BOUND 1000000

typedef struct node {
    struct node* prev;
    int value;
} node;

int test_chain(int* array, long num);
long factorial(long num);
long next_value(long num);
node* list_insert(node* init, long num);
int list_search(node* current, long num, int index);
void enter_and_free(int* array, node* init, int start, long repeat, bool constant);

int main(void) {
    int result = 0;
    int* array = calloc(BOUND * 10, sizeof(bool));
    
    for (long i = 69; i < BOUND; i++) {
        if (!array[i]) {
            int length = test_chain(array, i);

            if (length == 60)
                result++;
        }
    }
    free(array);
    printf("%d\n", result);
}

int test_chain(int* array, long num) {
    node* init = malloc(sizeof(node));
    init->prev = NULL;
    init->value = num;
    int length = 1;
    bool done = false;
    
    while(!done) {
        long next = next_value(num);
        if (array[next] != 0) {
            enter_and_free(array, init, array[next] + 1, next, false);
            length += array[next] - 1;
            done = true;
        }
        int index = list_search(init, next, 1);
        if (index != -1) {
            enter_and_free(array, init, length - index + 1, next, true);
            done = true;
        }
        else {
            init = list_insert(init, next);
            num = next;
            length++;
        }
    }
    return length;
}

long factorial(long num) {
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}

long next_value(long num) {
    int lim = log10(num) + 1;
    long result = 0;
    for (int i = 0; i < lim; i++) {
        result += factorial(num % 10);
        num = (num - num % 10) / 10;
    }
    return result;
}

node* list_insert(node* init, long num) {
    node* new = malloc(sizeof(node));
    new->value = num;
    new->prev = init;
    return new;
}

int list_search(node* current, long num, int index) {
    if (current == NULL)
        return -1;
    else if (current->value == num)
        return index;
    else
        return list_search(current->prev, num, index + 1);
}

void enter_and_free(int* array, node* init, int start, long repeat, bool constant) {
    if (init != NULL) { 
        if (constant == true) {
            if (init->value == repeat) {
                array[init->value] = start;
                node* next = init->prev;
                free(init);
                enter_and_free(array, next, start + 1, repeat, false);
            }
            else {
                array[init->value] = start;
                node* next = init->prev;
                free(init);
                enter_and_free(array, next, start, repeat, true);
            }
        }
        else {
            array[init->value] = start;
            node* next = init->prev;
            free(init);
            enter_and_free(array, next, start + 1, repeat, false);
        }
    }
}
