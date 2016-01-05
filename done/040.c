#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    long num = 1;
    long count = 1;
    long product = 1;
    bool flag = true;
    
    while (flag)
    {
        long sample = num;
        int places = log10(sample) + 1;
        for (int i = places - 1; i >= 0; i--)
        {
            int digit = sample / pow(10, i);
            if (count == 1 || count == 10 || count == 100 || count == 1000 || count == 10000 || count == 100000 || count == 1000000)
            {
                product *= digit;
                if (count == 1000000)
                    flag = false;
            }
            sample = sample - digit * pow(10, i);
            count++;
        }
        num++;
    }
        
    printf("%ld\n", product);
}
