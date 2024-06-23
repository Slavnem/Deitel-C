// Slavnem @2024-06-23
// Üç Sayının En Küçüğünü Hesaplamak

// Kütüphaneler
#include <stdio.h>

// MINIMUM2 tanımlıysa kaldırsın
#ifdef MINIMUM2
#undef MINIMUM2
#endif

// MINIMUM2 ile en küçük olanı hesaplama
#define MINIMUM2(x,y) (x < y ? x : y)

// MINIMUM3 tanımlıysa kaldırsın
#ifdef MINIMUM3
#undef MINIMUM3
#endif

// MINIMUM3 tanımlama
#define MINIMUM3(x,y,z) (x < y ? MINIMUM2(x,z) : MINIMUM2(y,z))

// main
int main(void)
{
    // kullanıcıdan 3 sayı almak için
    int sayi1, sayi2, sayi3;

    // Kullanıcıdan sayı almak
    printf("3 adet sayi giriniz: ");
    scanf("%d %d %d", &sayi1, &sayi2, &sayi3);

    // İki sayıdan küçüğünü hesaplamak
    printf("sayi1(%d), sayi2(%d) ve sayi3(%d) en kucugu = %d\n",
        sayi1, sayi2, sayi3,
        MINIMUM3(sayi1, sayi2, sayi3)
    );
}