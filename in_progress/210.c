#include <stdio.h>
#include <math.h>

#define R 1000000000

long long obstuse_points(long long r);
long double pos_quad_root(long double a, long double b, long double c);

int main(void) {
    printf("%lld\n", obstuse_points(R));
}

long long obstuse_points(long long r) {
    long double root2 = 1. - sqrtl(2.);
    long long result = r * r * 3 / 4;
    for (long long b = 1; b <= r / 4 - 1; ++b) {
        long double c = root2 * (r / 4) * (r / 4) + (b - r / 4) * (b - r / 4);
        long double circ_point = pos_quad_root(2, -2 * b, c);
            result += 2 * (floor(b / 2) - ceil(circ_point) + 1);
    }
    long double circ_point = pos_quad_root(2, 2 * r / 4, 0);
    result += (floor(r / 8) - ceil(circ_point) + 1);
    return result;
}

long double pos_quad_root(long double a, long double b, long double c) {
    long double discriminant = b * b - 4 * a * c;
    return (-1. * b + sqrtl(discriminant)) / (2. * a);
}
