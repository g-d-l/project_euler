#include <stdio.h>

#define SUM 200
#define COINS {1, 2, 5, 10, 20, 50, 100, 200}
#define COIN_COUNT 8

int main(void) {
    int denoms[COIN_COUNT] = COINS;
    int totals[SUM + 1];
    for (int i = 0; i <= SUM; i++)
        totals[i] = 1;
    for (int i = 1; i < COIN_COUNT; i++) {
        for (int j = denoms[i]; j <= SUM; j++)
            totals[j] += totals[j - denoms[i]];
    }
    printf("%d\n", totals[SUM]);
}
