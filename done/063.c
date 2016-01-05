#include <stdio.h>
#include <math.h>

int main(void) {
    int total = 0;
    int base = 9;
    int exp = 1;
    while ((int) (log10(base) * exp + 1) == exp) {
        int base_copy = base;
        while ((int) (log10(base_copy) * exp + 1) == exp) {
            base_copy--;
            total++;
        }
        exp++;
    }
    printf("%d\n", total);
}    
