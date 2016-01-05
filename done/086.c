#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPerfSquare(long long num);

int main(void) {
    int M = 1;
    int integer_paths = 0;
    while (integer_paths <= 2000) {
        M++;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= i; j++) {
                if (isPerfSquare(M * M + (i + j) * (i + j)))
                    integer_paths++;
            }
        }
    }
    printf("%d\n", integer_paths);
}

bool isPerfSquare(long long num) {
    long long root = sqrtl(num);
    return root * root == num;
}
