#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool ptest(long num);

int main(void)
{
    bool ender = true;
    long number = 57;
    
    while(ender)
    {
        if (!ptest(number))
        {
            ender = false;
            long end = sqrt(number / 2);
            for (long i = 1; i <= end; i++)
            {
                if (ptest(number - 2 * i * i))
                {
                    ender = true;
                    break;
                }
            }
        }
        number += 2;
    }
    printf("%ld\n", number - 2);
}


bool ptest(long num)
{
    long limit = sqrt(num);
    for (long i = 2; i <= limit; i++)
    {
        if ((long) num / i == (float) num / i)
        {
            return false;
        }
    }
    return true;
}
