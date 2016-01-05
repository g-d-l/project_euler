#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE_BOUND 100
#define EXP_BOUND 63
#define COUNT 30

typedef struct node {
    unsigned long long val;
    int base;
    int exp;
} node;

int compare(const void* a, const void* b);
int digit_sum(unsigned long long n);

int main(void) {
    node* array = malloc(sizeof(node) * BASE_BOUND * EXP_BOUND);
    unsigned long long val;
    int index = 0;
    for (int base = 2; base <= BASE_BOUND; ++base) {
        val = base;
        int exp = 1;
        int exp_limit = EXP_BOUND / log2l(base);
        while (val * base < 10) {
            val *= base;
            ++exp;
        }
        
        while (exp < exp_limit) {
            val *= base;
            ++exp;
            array[index].val = val;
            array[index].base = base;
            array[index].exp = exp;
            ++index;
        }        
    }
    qsort(array, index, sizeof(node), compare);
    int count = 0;
    index = 0;
    while (1) {
        if (digit_sum(array[index].val) == array[index].base) {
            ++count;
            if (count == COUNT)
                break;
        }
        ++index;
    }
    printf("%lld\n", array[index].val);
    free(array);
}

int compare(const void* a, const void* b) {
    node* a_ptr = (node*) a;
    node* b_ptr = (node*) b;
    if (a_ptr->val > b_ptr->val)
        return 1;
    else if (a_ptr->val < b_ptr->val)
        return -1;
    else
        return 0;
}

int digit_sum(unsigned long long n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n = (n - n % 10) / 10;
    }
    return sum;
}
