#include <stdio.h>

int main(void)
{
    int array[302] = {0};
    array[301] = 2;
    int end = 301;
    
    for (int i = 1; i < 1000; i++)
    {
        for (int j = 301; j >= end; j--)
        {
            array[j] *= 2;
        }
        for (int j = 301; j >= end; j--)
        {
            if (array[j] > 9)
            {
                array[j] -= 10;
                array[j - 1] += 1;
            }
        }        
        if (array[end - 1] != 0)
            end--;
    }
    
    int sum = 0;
    for (int i = 301; i >= end; i--)
        sum += array[i];
    
    printf("%d\n", sum); 
}
