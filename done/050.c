#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool ptest(long num);

int main(void)
{
    long primes[500000];
    primes[0] = 2;
    primes[1] = 3;
    
    long index = 1;
    long max = 0;
    long maxseries = 0;
    
    for (long j = 1; j <= 166666; j++)
    {
        long a = 6 * j - 1;
        if (ptest(a))
            primes[index++] = a;
        if (ptest(a + 2))
            primes[index++] = a + 2; 
    }
    
    for (long i = 3; i <= index; i++)
    {
        for (long j = 0; j <= i / 2; j++)
        {
            long sum = 0;
            long start = j;
            while (sum < primes[i])
            {
                sum += primes[start++];
            }
            if (sum == primes[i])
                if (start - j > maxseries)
                {
                    maxseries = start - j;
                    max = primes[i];
                }
        } 
    }
    
    printf("%ld\n", max);
    
    

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
