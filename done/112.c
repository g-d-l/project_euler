#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool check(long long num);

int main(void) {
    bool goOn = true;
    long long counter = 100;
    long long bounceCount = 0;
    while(goOn) {
        if (check(counter))
            bounceCount++;
        if ((counter - bounceCount) * 99 == bounceCount)
            goOn = false;
        else
            counter++;
    }
    printf("%lld\n", counter);
}

bool check(long long num) {
    long long copy = num;
    int length = log10(copy) + 1;
    int* array = calloc(length + 1, sizeof(int));
    for (int i = length - 1; i >= 0; i--) {
        array[i] = copy % 10;
        copy = (copy - array[i]) / 10;
    }
    int start = 1;
    while (start < length && array[start] == array[start - 1])
        start++;
    start--;
    if (start == length - 1)
        return false;
    else {
        if (array[start] > array[start + 1]) {
            for (int i = start; i < length - 1; i++) {
                if (array[i] < array[i + 1])
                    return true;
            }
            return false;
        }
        else {
            for (int i = start; i < length - 1; i++) {
                if (array[i] > array[i + 1])
                    return true;
            }
            return false;
        }
    }
}
