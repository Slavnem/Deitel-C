// Slavnem @2024-06-23
// Kürenin Hacmini Hesaplama

// Kütüphaneler
#include <stdio.h>
#include <assert.h>

// Sabit tanımlamalar
#define COUNTER_MIN 1
#define COUNTER_MAX 10

// Küre hacim hesaplama makrosu
#define PI 3.14159
#define KURE_HACIM(x) ((4/3) * (PI) * ((x) * (x) * (x)))

// main
int main(void)
{
    // sayaç 1 ile 10 arası olmalı
    assert(COUNTER_MIN == 1);
    assert(COUNTER_MAX == 10);

    // döngü için sayaç
    int sayac;
    
    // sayaç bitene kadar dönsün
    for(sayac = COUNTER_MIN; sayac <= COUNTER_MAX; sayac++)
    {
        printf("%2d kure icin hacim: %.3f\n", sayac, KURE_HACIM(sayac));
    }
}