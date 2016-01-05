#include <stdio.h>

#define DIM 50

int main(void) {
    int count = 0;
    for (int x0 = 0; x0 <= DIM; x0++) {
        for (int y0 = (x0 == 0) ? 1 : 0; y0 <= DIM; y0++) {
            for (int x1 = 0; x1 <= DIM; x1++) {
                for (int y1 = (x1 == 0) ? 1 : 0; y1 <= DIM; y1++) {
                    if (x0 * y1 != x1 * y0) {
                        int slope0_n = y0;
                        int slope0_d = x0;
                        int slope1_n = y1;
                        int slope1_d = x1;
                        int slope01_n = y0 - y1;
                        int slope01_d = x0 - x1;
                        
                        if (slope0_d * slope1_d == -1 * slope0_n * slope1_n)
                            count++;
                        else if (slope0_d * slope01_d == -1 * slope0_n * slope01_n)
                            count++;
                        else if (slope01_d * slope1_d == -1 * slope01_n * slope1_n)
                            count++;
                    }                    
                }
            }
        }
    }
    printf("%d\n", count / 2);
}
