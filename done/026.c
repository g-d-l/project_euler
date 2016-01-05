#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 1000

typedef struct node {
    struct node* next;
    int val;
} node;

int checkAndAddVal(node* init, int val);
void free_list(node* init);

int main(void) {
    int max_length = 0;
    int max_d;
    for (int i = 2; i < LIMIT; i++) {
        node* init = malloc(sizeof(node));
        init->next = NULL;
        init->val = -1;
        int n = 10;
        bool done = false;
        while (!done) {
            if (n == 0) {
                done = true;
                free_list(init);
            }
            else {
                int length = checkAndAddVal(init, n);
                if (length == 0)
                    n = (n % i) * 10;
                else {
                    if (length > max_length) {
                        max_length = length;
                        max_d = i;
                    }
                    done = true;
                    free_list(init);
                }
            }
        }
    }
    printf("%d\n", max_d);
}

int checkAndAddVal(node* init, int val) {
    if (val == init->val) {
        int length = 0;
        while (init != NULL) {
            init = init->next;
            length++;
        }
        return length;
    }
    else {
        if (init->next == NULL) {
            node* new = malloc(sizeof(node));
            new->next = NULL;
            new->val = val;
            init->next = new;
            return 0;
        }
        else
            return checkAndAddVal(init->next, val);
    }
}


void free_list(node* init) {
    if (init != NULL) {
        free_list(init->next);
        free(init);
    }
}
