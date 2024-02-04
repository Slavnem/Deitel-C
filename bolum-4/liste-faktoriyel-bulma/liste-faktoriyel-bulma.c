//Liste Faktoriyel Bulma
#include <stdio.h>

int main( void )
{
    for(int i = 1; i < 20; i++)
    {
        unsigned int carpim = 1;

        for(int j = 1; j <= i; j++)
        {
            carpim *= j;
        }

        printf("%d)faktoriyel = %d\n", i, carpim);
    }
}