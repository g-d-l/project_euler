#include <stdio.h>
 
const char * donuts[] = { "0", "1", "2", "3", "4", "something completely different" };
long choose(int * got, int n_chosen, int len, int at, int max_types)
{
        int i;
        long count = 0;
        if (n_chosen == len) {
                if (!got) return 1;
 
                for (i = 0; i < len; i++)
                        printf("%s", donuts[got[i]]);
                printf("\n");
                return 1;
        }
 
        for (i = at; i < max_types; i++) {
                if (got) got[n_chosen] = i;
                count += choose(got, n_chosen + 1, len, i, max_types);
        }
        return count;
}
 
int main()
{
        int chosen[5];
        choose(chosen, 0, 3, 0, 5);
 
        printf("\nWere there ten donuts, we'd have had %ld choices of three\n",
                choose(0, 0, 3, 0, 10));
        return 0;
}
