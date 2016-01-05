#include <stdio.h>

void recur(int a);

int main(void)
{
    recur(40);
}

void recur(int a)
{
    int count = a;
    
    printf("0");
    count--;
    recur(count);
    printf("1");
    if (count == 0)
    printf("\n");
       
}
