#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* array = malloc(sizeof(int) * 251000);
    for (int i = 1; i <= 250000; ++i) {
        int result = 1;
        for (int j = 1; j <= i; ++j) {
            result = (result * i) % 250;
        }
        array[i] = result;
    }
}
