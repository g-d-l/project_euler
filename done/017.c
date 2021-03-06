#include <stdio.h>

#define LIMIT 1000

int main(void)
{
    int letters[101];
    letters[0] = 0;
    letters[1] = 3;
    letters[2] = 3;
    letters[3] = 5;
    letters[4] = 4;
    letters[5] = 4;
    letters[6] = 3;
    letters[7] = 5;
    letters[8] = 5;
    letters[9] = 4;
    letters[10] = 3;
    letters[11] = 6;
    letters[12] = 6;
    letters[13] = 8;
    letters[14] = 8;
    letters[15] = 7;
    letters[16] = 7;
    letters[17] = 9;
    letters[18] = 8;
    letters[19] = 8;
    letters[20] = 6;
    letters[30] = 6;
    letters[40] = 5;
    letters[50] = 5;
    letters[60] = 5;
    letters[70] = 7;
    letters[80] = 6;
    letters[90] = 6;
    letters[100] = 7;
    
    int result = 11;
    
    for (int i = 1; i < LIMIT; i++) {
        if (i >= 100) {
            result += letters[i / 100];
            result += letters[100];
            if (i % 100 != 0)
                result += 3;
        }
        if (i % 100 > 20) {
            result += letters[i % 100 - i % 10];
            result += letters[i % 10];
        }
        else
            result += letters[i % 100];
    }
    printf("%d\n", result);
}
