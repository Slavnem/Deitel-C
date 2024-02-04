//Çift Sayılar Toplama
#include <stdio.h>

int main( void )
{
    unsigned int toplam = 0;

    for(int i = 2; i < 30 && i % 2 == 0; i += 2)
    {
        toplam += i;
    }

    printf("2'den 30'a kadar cift sayilar toplami = %d\n", toplam);
}