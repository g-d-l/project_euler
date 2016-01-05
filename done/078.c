#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define FACTOR 1000000

void next_value(long long* coin_array, int index);
int get_pentagonal_num(int n);

int main(void) {
    long long* coin_array = malloc(sizeof(long long) * 1000000);
    coin_array[0] = 1;
    int index = 1;
    next_value(coin_array, index);
    while(coin_array[index] % FACTOR != 0) {
        next_value(coin_array, ++index);
    }
    free(coin_array);
    printf("%d\n", index);
}

void next_value(long long* coin_array, int index) {
    long long sum = 0;
    int n = 1;
    int pentagonal = get_pentagonal_num(n);
    while (pentagonal <= index) {
        if (abs(n) % 2 == 1)        
            sum += (coin_array[index - pentagonal]) % FACTOR;
        else
            sum -= (coin_array[index - pentagonal]) % FACTOR;
        n = (n < 0) ? -1 * n + 1 : -1 * n;
        pentagonal = get_pentagonal_num(n);
    }
    coin_array[index] = sum;
}

int get_pentagonal_num(int n) {
    return (n * (3 * n - 1)) / 2;
}
