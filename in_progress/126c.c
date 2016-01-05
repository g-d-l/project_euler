#include <stdio.h>
 
void generate(int pos, int* elements, int* current, int T, int N) {
    if (pos == N) {
        for (int i = 0; i < N; i++)
            printf("%d", current[i]);
        printf("\n");
    }
    else {
        for (int i = 0; i < T; i++) {
            current[pos] = elements[i];
            generate(pos + 1, elements, current, T, N);
        }
    }
}
 
int main(void) {
    int elements[4] = {0, 1, 2, 3};
    int current[2];
    generate(0, elements, current, 4, 2);
}
