#include <stdio.h>

#define MAXD 1000000
#define RIGHTN 3
#define RIGHTD 7

int gcf(int a, int b);

int main(void) {
    long double right_val = (long double) RIGHTN / RIGHTD;
    long double min_dist = 1;
    int min_dist_n;
    for (int d = 3; d <= MAXD; d++) {
        int n = (d * RIGHTN) / RIGHTD;
        if (d % RIGHTD == 0)
            --n;
        while (gcf(d, n) > 1)
            --n;
        long double dist = right_val - (long double) n / d;
        if (dist < min_dist) {
            min_dist_n = n;
            min_dist = dist;
        }
    }
    printf("%d\n", min_dist_n);
}

int gcf(int a, int b) {
    int r = a % b;
    if (r == 0)
        return b;
    else
        return gcf(b, r);
}
