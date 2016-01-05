#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    long long sum = 0;
    int divisors = 0;
    long long adder = 0;
    while (true)
    {
        sum = sum + adder;
        for (long long j = 1; j <= sum; j++)
        {
            if ((long long) sum / j == (long double) sum / j)
            {
                divisors++;
            }
        }
        if (divisors > 500)
        {
            break;
        }
        divisors = 0;
        adder++;
    }
    printf("%lld\n", sum);

}
