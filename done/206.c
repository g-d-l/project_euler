#include <stdio.h>
#include <stdbool.h>

#define START 1010101010

bool testPattern(long long val);

int main(void) {
    long long val = START;
    bool done = false;
    while (!done) {
        if (testPattern(val * val))
            done = true;
        else
            val += 10;
    }
    printf("%lld\n", val);
}

bool testPattern(long long val) {
    val /= 10;
    for (int i = 9; i >= 1; i--) {
        int last_two = val % 100;
        if ((last_two - last_two % 10) / 10 != i)
            return false;
        else
            val = (val - val % 100) / 100;
    }
    return true;
}
