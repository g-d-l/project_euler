#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    long long sqofsum = 0;
    for (int i = 1; i <= 100; i++)
    {
        sqofsum = (long long) sqofsum + i;
    }
    
    sqofsum = sqofsum * sqofsum;
    
    long long sumofsqs = 0;
    for (int i = 1; i <= 100; i++)
    {
        sumofsqs = (long long) sumofsqs + i * i;
    }
    
    printf("%lld\n", sqofsum - sumofsqs);
}
