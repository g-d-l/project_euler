#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool ptest(int num);

int main(void)
{
    int primes[1000];
    primes[0] = 2;
    primes[1] = 3;
    
    int count = 2;
    
    for (int j = 1; j <= 166; j++)
    {
        int a = 6 * j + 1;
        if (ptest(a))
        {
            primes[count++] = a;
        }
        if (ptest(a - 2))
        {
            primes[count++] = a - 2;
        }   
    }
    
    int maxa = 0;
    int maxb = 0;
    int series = 0;
    
    for (int i = -999; i < 1000; i++)
    {
        for (int j = 0; j < count; j++)
        {
            int n = 0;
            int total = 0;
            int d = n * n + i * n + primes[j];
            
            while (ptest(d) && d > 0)
            {
                n++;
                total++;
                d = n * n + i * n + primes[j];
            }
            if (total > series)
            {
                series = total;
                maxa = i;
                maxb = primes[j];
            }
        }
    }
    
    printf("%d, %d\n", maxa, maxb);
    
    
    
    
}


bool ptest(int num)
{
    int limit = sqrt(num);
    for (int i = 2; i <= limit; i++)
    {
        if ((int) num / i == (float) num / i)
        {
            return false;
        }
    }
    return true;
}
