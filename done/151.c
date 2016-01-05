#include <stdio.h>
#include <stdbool.h>

double recurse(int a2, int a3, int a4, int a5);

int main(void) {
    printf("%.6f\n", recurse(1, 1, 1, 1));
}

double recurse(int a2, int a3, int a4, int a5) {
    if (a2 + a3 + a4 + a5 == 1) {
        if (a2 == 1)
            return recurse(0, 1, 1, 1) + 1.;
        else if (a3 == 1)
            return recurse(0, 0, 1, 1) + 1.;
        else if (a4 == 1)
            return recurse(0, 0, 0, 1) + 1.;
        else
            return 0;
    }
    else {
        double pick_a2 = (a2 > 0) ? a2 * recurse(a2 - 1, a3 + 1, a4 + 1, a5 + 1) : 0;
        double pick_a3 = (a3 > 0) ? a3 * recurse(a2, a3 - 1, a4 + 1, a5 + 1) : 0;
        double pick_a4 = (a4 > 0) ? a4 * recurse(a2, a3, a4 - 1, a5 + 1) : 0;
        double pick_a5 = (a5 > 0) ? a5 * recurse(a2, a3, a4, a5 - 1) : 0;
        return (pick_a2 + pick_a3 + pick_a4 + pick_a5) / (a2 + a3 + a4 + a5);
    }
}
