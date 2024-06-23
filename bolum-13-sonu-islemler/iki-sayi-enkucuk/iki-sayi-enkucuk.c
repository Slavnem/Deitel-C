// Slavnem @2024-06-23
// İki Sayının En Küçüğünü Hesaplamak

// Kütüphaneler
#include <stdio.h>

// MINIMUM2 tanımlıysa kaldırsın
#ifdef MINIMUM2
#undef MINIMUM2
#endif

// MINIMUM2 ile en küçük olanı hesaplama
#define MINIMUM2(x,y) (x < y ? x : y)

// main
int main(void)
{
    // kullanıcıdan 2 sayı almak için
    int sayi1, sayi2;

    // Kullanıcıdan sayı almak
    printf("2 adet sayi giriniz: ");
    scanf("%d %d", &sayi1, &sayi2);

    // İki sayıdan küçüğünü hesaplamak
    printf("sayi1(%d) ile sayi2(%d) en kucugu = %d\n", sayi1, sayi2, MINIMUM2(sayi1, sayi2));
}