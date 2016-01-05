#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int count = 3;
    int primecount = 1;
    int current = 2;
    while (true)
    {
        for (int i = 2; i < count; i++)
        {
            if ((int) count / i == (double) count / i)
            {
                count++;
                break;
            }
            else if (i == count - 1)
            {
                current = count;
                primecount++;
                count++;
                break;
            }
        }
        if (primecount == 10001)
        {
            break;
        }
    }
    
    printf("%d\n", current);
}
