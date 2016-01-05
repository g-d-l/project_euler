#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int droplast(int in)
{   
    return (in - (in % 10)) / 10;
}


bool check5(int in)
{
    if (droplast(droplast(droplast(droplast(in)))) == in % 10)
    {
        if (droplast(droplast(droplast(in))) % 10 == droplast(in) % 10)
        {
            return true;
        }
    }
    return false;
}



bool check6(int in)
{
    if (droplast(droplast(droplast(droplast(droplast(in))))) == in % 10)
    {
        if (droplast(droplast(droplast(droplast(in)))) % 10 == droplast(in) % 10)
        {
            if (droplast(droplast(droplast(in))) % 10 == droplast(droplast(in)) % 10)
            {
                return true;
            }
        }
    }
    return false;
}


int main(void)
{
    int top = 0;
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 100; j < 1000; j++)
        {
            int test = i * j;
            if ((int) log10(test) + 1 == 5)
            {
                if (check5(test) == true)
                {
                    if (test > top)
                    {
                        top = test;
                    }
                }
            }
            else
            {
                if (check6(test) == true)
                {
                    if (test > top)
                    {
                        top = test;
                    }
                }
            }
        }
    }
    
    printf("%d\n", top);
}



