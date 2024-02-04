//Tek Sayıların Çarpımını Bulma
#include <stdio.h>

int main( void )
{
    unsigned int carpim = 1;

    for(int i = 1; i < 15; i += 2)
    {
        carpim *= i;
    }

    printf("1'den 15'e kadar tek sayilarin carpimi = %d\n", carpim);
}