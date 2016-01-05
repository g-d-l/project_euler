#include <stdio.h>

int main(void)
{
    int first = 1;
    int second = 1;
    int sum = 0;
    while (first < 4000000 && second < 4000000)
    {
        int temp = first;
        first = second;
        second = first + temp;
        if (second % 2 == 0)
        {
            sum = sum + second;
        }
    }
    
    printf("%d\n", sum);
}
