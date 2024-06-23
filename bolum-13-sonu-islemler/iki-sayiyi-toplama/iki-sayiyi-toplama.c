// Slavnem @2024-06-23
// İki Sayıyı Makro İle Toplama

// Kütüphaneler
#include <stdio.h>

// Toplama makrosu tanımlıysa tanımı kaldırsın
#ifdef SUM
#undef SUM
#endif

// Toplama makrosunu oluştursun
#define SUM(x,y) ((x) + (y))

// main
int main(void)
{
    printf("x(3) toplam y(6) = %d\n", SUM(3,6));
}