#include <stdio.h>
#include <math.h>

#define LIMIT 100000000
#define PLACES 5

int main(void) {
    int g = 1;
    int mod = pow(10, PLACES);
    for (int i = 2; i <= LIMIT; i++) {
        g *= i;
        while (g % 10 == 0)
            g /= 10;
        g %= mod;
    }
    printf("%d\n", g % mod);
}
