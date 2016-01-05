#include <stdio.h>

int main(void)
{
    int array[158] = {0};
    array[157] = 1;
    int end = 157;
    
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 157; j >= end; j--)
        {
            array[j] *= i;
        }
        for (int j = 157; j >= end - 2; j--)
        {
            if (array[j] > 9)
            {
                int newplace = array[j] % 10;
                int carry = (array[j] - newplace) / 10;
                array[j] = newplace;
                array[j - 1] += carry;
            }
        }        
        if (array[end - 1] != 0 && array[end - 2] == 0)
            end--;
        else if (array[end - 2] != 0)
            end -= 2;
    }
    
    int sum = 0;
    for (int i = 157; i >= end; i--)
        sum += array[i];
    
    printf("%d\n", sum); 
}
