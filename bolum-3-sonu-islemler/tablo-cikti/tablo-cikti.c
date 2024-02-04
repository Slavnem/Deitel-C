#include <stdio.h>

int main( void )
{
    unsigned int onluk = 10, yuzluk = 100, binlik = 1000;

    for(int i = 1; i <= 10; i++)
    {
        printf("%d\t%d\t%d\n", (onluk * i), (yuzluk * i), (binlik * i));
    }
}
