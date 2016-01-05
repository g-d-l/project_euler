#include <stdio.h>

#define TARGET 100

int main(void) {
    int array[TARGET + 1] = {1};
    for (int i = 1; i <= TARGET; i++) {
        for (int j = i; j <= TARGET; j++) {
            array[j] += array[j - i];
        }
    }
    printf("%d\n", array[TARGET] - 1);
}
