#include <stdio.h>
#include <stdbool.h>

#define BOUND 1000

long cubes_in_layer(int l, int w, int h, int layer);
bool has_layer_size(int l, int w, int h, long target);
int find_limit(int fixed_1, int fixed_2, int bound);
int min(int a, int b);

int main(void) {
    long n = 154;
    bool done = false;
    while (!done) {
        int count = 0;
        int max_l = find_limit(1, 1, n);
        for (int l = 1; l <= max_l; l++) {
            int max_w = min(l, find_limit(l, 1, n));
            for (int w = 1; w <= max_w; w++) {
                int max_h = min(w, find_limit(l, w, n));
                for (int h = 1; h <= max_h; h++) {
                    if (has_layer_size(l, w, h, n)) {
                        count++;
                    }
                }
            }
        }
        if (count == BOUND) {
            done = true;
            printf("%ld\n", n);
        }
        else {
            n += 2;
            printf("%ld - %d\n", n, count);
        }
    }
}

long cubes_in_layer(int l, int w, int h, int layer) {
    long flats = 2 * (l * w + w * h + l * h);
    long slants = 4 * (layer - 1) * (l + h + w);
    long corners = 4 * (layer - 2) * (layer - 1);
    return flats + slants + corners;
}

bool has_layer_size(int l, int w, int h, long target) {
    int layer = 1;
    long cubes = cubes_in_layer(l, w, h, layer);
    while (cubes < target)
        cubes = cubes_in_layer(l, w, h, ++layer);
    return (cubes == target);
}

int find_limit(int fixed_1, int fixed_2, int bound) {
    int max = 0;
    do
        max++;
    while (cubes_in_layer(max, fixed_1, fixed_2, 1) <= bound);
    return max - 1;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

