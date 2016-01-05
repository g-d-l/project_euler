#include <stdio.h>
#include <stdbool.h>

long gcd(long a, long b);

int main(void)
{
    int array[8];
    int count = 0;
    bool done = false;
    
    for (int a = 1; a < 9 && done == false; a++)
    {
        for (int b = a + 1; b < 10 && done == false; b++)
        {
            for (int c = 1; c < 10 && done == false; c++)
            {
                int ac = 10 * a + c;
                int ca = 10 * c + a;
                int bc = 10 * b + c;
                int cb = 10 * c + b;
                
                if (bc * a == b * ac)
                {
                    array[count] = ac;
                    count++;
                    array[count] = bc;
                    count++;
                    if (count == 8)
                        done = true;  
                }
                if (cb * a == b * ac)
                {
                    array[count] = ac;
                    count++;
                    array[count] = cb;
                    count++;
                    if (count == 8)
                        done = true;  
                }
                if (cb * a == b * ca)
                {
                    array[count] = ca;
                    count++;
                    array[count] = cb;
                    count++;
                    if (count == 8)
                        done = true;  
                }
                if (bc * a == b * ca)
                {
                    array[count] = ca;
                    count++;
                    array[count] = bc;
                    count++;
                    if (count == 8)
                        done = true;  
                }
            }
        }
    }
    
    long numerator = 1;
    long denominator = 1;
    
    for (int i = 0; i < 8; i += 2)
        numerator *= array[i];
    for (int i = 1; i < 8; i += 2)
        denominator *= array[i];
    
    printf("%ld\n", denominator / gcd(denominator, numerator));
    
}

long gcd(long a, long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
