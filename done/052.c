#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void indexer(long long num, int* array);
bool checker(void);

int array1x[10] = {0};
int array2x[10] = {0};
int array3x[10] = {0};
int array4x[10] = {0};
int array5x[10] = {0};
int array6x[10] = {0};
int size = sizeof(array1x);

int main(void) {
   
    bool search = true;
    long long count = 15167;
    
    while (search) {
        if ((int) log10l(count) == (int) log10l(6 * count)) {
            indexer(count, array1x);
            indexer(2 * count, array2x);
            indexer(3 * count, array3x);
            indexer(4 * count, array4x);
            indexer(5 * count, array5x);
            indexer(6 * count, array6x);
            
            if (checker())
                search = false;
            else {
                count++;
                memset(array1x, 0, size);
                memset(array2x, 0, size);    
                memset(array3x, 0, size);    
                memset(array4x, 0, size);    
                memset(array5x, 0, size);    
                memset(array6x, 0, size);
            }         
        }
        else
            count++;
    }
    printf("%lld\n", count);
}

void indexer(long long num, int* array) {
    for (int i = 0, end = log10l(num) + 1; i < end; i++) {
        array[num % 10] += 1;
        num = (num - num % 10) / 10;
    }
}
    
bool checker(void) {
    for (int i = 0; i < 10; i++) {
        if (array1x[i] == array2x[i])
            if (array2x[i] == array3x[i])
                if (array3x[i] == array4x[i])
                    if (array4x[i] == array5x[i])
                        if (array5x[i] == array6x[i])
                            ;        
                        else
                            return false;
                    else
                        return false;                                 
                else
                    return false;
            else
                return false;
        else
            return false;
    }
    return true;
}
