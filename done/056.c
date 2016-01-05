#include <stdio.h>
#include <math.h>

#define MAX 99

int reset_array(int* array, int places);
int digit_sum(int* array, int places, int start);
int multiply(int* array, int places, int start, int num);

int main(void) {
    int places = log10(MAX) * MAX;
    int array[places];
    int start;
    int max_sum = 0;
    for (int i = 1; i <= MAX; i++) {
        start = reset_array(array, places);
        for (int j = 1; j <= MAX; j++) {
            start = multiply(array, places, start, i);
            int sum = digit_sum(array, places, start);
            if (sum > max_sum)
                max_sum = sum;
        }
    }
    printf("%d\n", max_sum);
}


int reset_array(int* array, int places) {
    for (int i = 0; i < places - 1; i++)
        array[i] = 0;
    array[places - 1] = 1;
    return places - 1;
}

int digit_sum(int* array, int places, int start) {
    int sum = 0;
    for (int i = start; i < places; i++)
        sum += array[i];
    return sum;
}

int multiply(int* array, int places, int start, int num) {
    int carry = 0;
    for (int i = places - 1; i >= start; i--) {
        int product = num * array[i] + carry;
        array[i] = product % 10;
        carry = product / 10;        
    }
    while (carry > 0) {
        array[--start] = carry % 10;
        carry /= 10;
    }
    return start;
}
