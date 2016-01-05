#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool ptest(long num);

int main(void)
{
    long primes[500000];
    primes[0] = 2;
    primes[1] = 3;
    
    int count = 2;
    
    for (long j = 1; j <= 166666; j++)
    {
        long a = 6 * j + 1;
        if (ptest(a))
        {
            primes[count++] = a;
        }
        if (ptest(a - 2))
        {
            primes[count++] = a - 2;
        }   
    }
    
    int total = 0;
    
    for (long i = 0; i < count; i++)
    {
        bool flag = true;
        long shift = primes[i];
        int places = log10(shift) + 1;
        for (int j = 0; j < places - 1; j++)
        {
            int digit = shift % 10;
            shift = (shift - digit) / 10 + pow(10, places - 1) * digit;
            if (!ptest(shift))
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            total++;
        }
    }
    printf("%d\n", total);
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
