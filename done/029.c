#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

int main(void) {
    int array[MAX + 1] = {0};
    int result = 0;
    for (int i = 2; i <= MAX; ++i) {
        if (!array[i]) {
            result += MAX - 1;
            int copy = i * i;
            int power = 2;
            while (copy <= MAX) {
                array[copy] = 1;
                result += MAX - 1;
                for (int j = 2; j <= MAX; ++j) {
                    for (int k = 1; k < power; ++k) {
                        if (power * j <= k * MAX && 
                            (power * j) % k == 0) {
                            --result;
                            break;
                        }
                    }
                }
                copy *= i;
                ++power;
            }
        }
    }
    printf("%d\n", result);
}
