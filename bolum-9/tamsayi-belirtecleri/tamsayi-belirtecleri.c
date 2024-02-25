// Slavnem @2024-02-25
// Tamsayı Belirteçleri

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    printf("%d\n", 455);
    printf("%i\n", 455); // printf ifadesinde i ile d aynıdır
    printf("%d\n", +455); // + işareti yazılmaz
    printf("%d\n", -455); // - işareti yazdırılır
    printf("%hd\n", 32000);
    printf("%ld\n", 2000000000L); // l öneki, sabiti long int tipine dönüştürür
    printf("%o\n", 455); // oktal - sekizli
    printf("%u\n", 455);
    printf("%u\n", -455);
    printf("%x\n", 455); // küçük harflerle hexadecimal
    printf("%X\n", 455); // büyük harflerle hexadecimal
}