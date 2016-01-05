#include <stdio.h>
#include <stdlib.h>

#define CAPACITORS 18

int total_circuits(int num);
bool insert_and_check(double* list, double val);

int main(void) {
    double* list = calloc(sizeof(double), total_circuits(CAPACITORS));
    
}

int total_circuits(int num) {
    if (num == 1)
        return 1;
    else
        return  (num * num - num + 2) / 2 + total_circuits(num - 1);
}

bool insert_and_check(double* list, double val) {
    int index = 0;
    while (list[index] != 0.) {
        if (fabs(list[index] - val) <= 0.00001)
            return true;
        else
            index++;
    }
    list[index] = val;
    return false;
}
