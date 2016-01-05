#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool tri(long long num);
bool pent(long long num);

int main(void)
{
    bool flag = true;
    long long integer = 144;
    while (flag)
    {
        long long number = 2 * integer * integer - integer;
        if (tri(number))
            if (pent(number))
            {
                printf("%lld\n", number);
                flag = false;
            }
        integer++;
    }
}

bool tri(long long num)
{
    if ((long) (-0.5 + sqrt(0.25 + 2 * num)) == (double) (-0.5 + sqrt(0.25 + 2 * num)))
        return true;
    return false;
}

bool pent(long long num)
{ 
    if ((long long) ((0.5 + sqrt(0.25 + 6 * num)) / 3) == (long double) ((0.5 + sqrt(0.25 + 6 * num)) / 3))
        return true;
    return false;
}
