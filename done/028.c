#include <stdio.h>

#define DIM 1001

int sum_on_diagonals(int dim);
int linear_sum(int n);
int quadratic_sum(int n);

int main(void) {
    printf("%d\n", sum_on_diagonals(DIM));
}

int sum_on_diagonals(int dim) {
    int layers = dim / 2 + 1;
    return 16 * quadratic_sum(layers) - 28 * linear_sum(layers) + 16 * layers - 3;
}

int linear_sum(int n) {
    return n * (n + 1) / 2;
}

int quadratic_sum(int n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}
