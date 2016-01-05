#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
    int top_line = 0;
    double top_10exponent = 0.;
    int line_counter = 1;
    FILE* list = fopen("099_numbers.txt", "r");
    int base = 0;
    int exp = 0;
    char c = fgetc(list);
    bool on_exp = false;
    while (c != EOF) {
        if (c >= 48 && c <= 57) {
            if (!on_exp)
                base = base * 10 + c - 48;
            else 
                exp = exp * 10 + c - 48;}
        else if (c == 44)
            on_exp = true;
        else {
            double exponent = log10(base) * exp;
            if (exponent > top_10exponent) {
                top_10exponent = exponent;
                top_line = line_counter;
            }
            base = 0;
            exp = 0;
            on_exp = false;
            line_counter++;
        }
    c = fgetc(list);
    }
    
    printf("%d\n", top_line);
}           
