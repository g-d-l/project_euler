#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    FILE* number = fopen("008_number.txt", "r");
    if (number == NULL)
    {
        return 1;
    }
    
    int topproduct = 0;
    
    while (true)
    { 
        char test[6];
          
        fread(test, sizeof(char), 5, number);
        fseek(number, sizeof(char) * -4, SEEK_CUR);
        
        if ((int) test[4] == 10)
        {
            break;
        }
        else
        {
            int testproduct = 1;
            
            for (int i = 0; i < 5; i++)
            {
                testproduct = testproduct * ((int) (test[i]) - '0');
            }
            
            if (testproduct > topproduct)
            {
                topproduct = testproduct;
            }
        }
    }
    
    printf("%d\n", topproduct);
}

