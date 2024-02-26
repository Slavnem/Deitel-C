// Slavnem @2024-02-26
// Sıcaklık Dönüşüm

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ön İşlemci Tanımlamaları
#define MIN_FAHRENHEIT 0
#define MAX_FAHRENHEIT 212

// main
int main(void)
{
    int fahrenheit;
    double celsius;

    srand(time(NULL)); // rastgele numara verme
    fahrenheit = (rand() % (MAX_FAHRENHEIT + 1)); // rastgele fahrenheit

    celsius = (5.0 / 9.0) * (fahrenheit - 32); // celsius hesaplama

    // test çıktısı
    printf("fahrenheit: %+-d\n", fahrenheit);
    printf("celsius: %+-.1f\n", celsius);
}