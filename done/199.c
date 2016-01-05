#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define ITERATIONS 10

long double recurse(long double k1, long double k2, long double k3, 
                    int iteration, int limit);
long double get_k(long double k1, long double k2, long double k3, bool outer);
long double get_area(long double k);

int main(void) {
    long double outer_k = get_k(1., 1., 1., true);
    long double inner_areas = recurse(1., 1., 1., 1., ITERATIONS);
    long double outer_areas = 3. * recurse(1., 1., outer_k, 1., ITERATIONS);
    long double result = 1. - (3. * get_area(1.0) + inner_areas + outer_areas) / get_area(outer_k);
    printf("%.8Lf\n", result);
}


long double recurse(long double k1, long double k2, long double k3, 
                    int iteration, int limit) {
    if (iteration == limit)
        return get_area(get_k(k1, k2, k3, false));           
    else {
        long double k = get_k(k1, k2, k3, false);
        long double next_iter = recurse(k, k2, k3, iteration + 1, limit) + 
                                recurse(k1, k, k3, iteration + 1, limit) +
                                recurse(k1, k2, k, iteration + 1, limit);
        return get_area(k) + next_iter;
    }
}

long double get_k(long double k1, long double k2, long double k3, bool outer) {
    if (outer)
        return k1 + k2 + k3 - 2 * sqrtl(k1 * k2 + k2 * k3 + k1 * k3);
    else
        return k1 + k2 + k3 + 2 * sqrtl(k1 * k2 + k2 * k3 + k1 * k3);
}

long double get_area(long double k) {
    return (1. / (k * k)) * 3.14159265359;
}
