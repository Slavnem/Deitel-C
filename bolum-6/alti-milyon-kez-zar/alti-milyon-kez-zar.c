// 6 MİLYON KEZ 6 YÜZLÜ ZAR ATMA
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 7

// main fonksiyonu ile programın başlaması
int main(void)
{
    size_t yuz; // 1-6 arası zar yüzü
    unsigned int atis; // atış sayacı 1-6.000.000
    unsigned int frekans[BOYUT] = { 0 }; // sayımları sıfırlamak

    srand(time(NULL)); // rastgele sayı üreteci

    // 6.000.000 defa zar atışı
    for(atis = 1; atis <= 6000000; ++atis)
    {
        yuz = 1 + (rand() % 6);
        ++frekans[yuz]; // tüm switch ifadelerinin yerine bunu kullanıyoruz
    } // döngü sonu

    printf("%s%17s\n", "Yuz", "Frequency");

    // 1-6 frekans aralığındaki elemanları çizelge şekilde yazdırmak
    for(yuz = 1; yuz < BOYUT; ++yuz)
    {
        printf("%4d%17d\n", yuz, frekans[yuz]);
    } // döngü sonu
} // main sonu