#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_perf_sq(long num);
bool test_choices(long x, long y, long z);

int main(void) {
    long x = 4;
    long y = 3;
    bool done = false;
    long result = 0;
    
    while(!done) {
        x++;
        y++;
        for (long y0 = 2; y0 <= y && !done; y0++) {
            for (long z0 = 1; z0 < y0 && !done; z0++) {

                if (test_choices(x, y0, z0)) {
                    result = x + y0 + z0;
                    done = true;
                }
            }
        }
    }
    printf("%ld\n", result);
}


bool is_perf_sq(long num) {
    long test_root = sqrtf((float) num);
    if (test_root * test_root == num)
        return true;
    return false;
}

bool test_choices(long x, long y, long z) {
    if (!is_perf_sq(x - y))
        return false;
    if (!is_perf_sq(x + y))
        return false;
    if (!is_perf_sq(x - z))
        return false;
    if (!is_perf_sq(x + z))
        return false;
    if (!is_perf_sq(y - z))
        return false;
    if (!is_perf_sq(y + z))
        return false;
    return true;
}
