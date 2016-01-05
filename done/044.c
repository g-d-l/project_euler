#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOUND 150000

int check_pentagonal(int n);

int main(void) {
    int done = 0;
    int index = 1;
    while (!done) {
        int pent = index * (3 * index - 1) / 2;
        for (int i = index - 1; i > 0; --i) {
            int pent2 = i * (3 * i - 1) / 2;
            if (check_pentagonal(pent + pent2) &&
                check_pentagonal(pent - pent2)) {
                printf("%d\n", pent - pent2);
                done = 1;
                break;
            }
        }
        ++index;
    }
}

int check_pentagonal(int n) {
    int discriminant = 1 + 8 * n * 3;
    int root = sqrt(discriminant);
    if (root * root != discriminant)
        return 0;
    else if ((1 + root) % 6 != 0)
        return 0;
    return 1;
    
}
