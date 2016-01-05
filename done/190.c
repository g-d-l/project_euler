#include <stdio.h>
#include <math.h>

#define LIMIT 15

long double get_product(int m);

int main(void) {
    int result = 0;
    for (int i = 2; i <= LIMIT; i++)
        result += get_product(i);
    printf("%d\n", result);
}

long double get_product(int m) {
    long double product = 1.;
    for (int i = 1; i <= m; i++)
        product *= powl((2. * i) / (m + 1), i);
    return product;
}
