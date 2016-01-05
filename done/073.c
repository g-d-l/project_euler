#include <stdio.h>
#include <math.h>

#define DMAX 12000

int gcf(int a, int b);

int main(void) {
    int result = 0;
    for (int d = 1; d <= DMAX; d++) { 
        int upper = (d % 2) ? d / 2 : d / 2 - 1;
        for (int n = d / 3 + 1; n <= upper; n++) {
            if (gcf(d, n) == 1)
                ++result;
        }
    }
    printf("%d\n", result);
}

int gcf(int a, int b) {
    int r = a % b;
    if (r == 0)
        return b;
    else
        return gcf(b, r);
}
