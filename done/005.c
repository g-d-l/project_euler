#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define LIMIT 20

int euclidean_gcd(int a, int b);

int main(void) {
    int result = 1;
    for (int i = 2; i <= LIMIT; i++)
        result *= i / euclidean_gcd(result, i);
    printf("%d\n", result);
}

int euclidean_gcd(int a, int b) {
    int r = a % b;
    if (r == 0)
        return b;
    else
        return euclidean_gcd(b, r);
}
