// Slavnem @2024-06-27
// Komut Satırı Argümanlarını Yazdırmak

// Kütüphaneler
#include <stdio.h>

// NULL ise 1, değilse 0
#define NULLER(x) (x == NULL)

// Bellek boş kontrolücüsü tanımlanmamışsa
#ifndef NULLER
#error "Bellek Boş Durumu Kontrolcüsü Tanımlanmamış!"
#endif

// Değişken isimlendirmeleri
typedef char* vstring;
typedef unsigned int uint;

// main
int main(int argc, vstring argv[])
{
    // argümanlar için sayaç
    uint argcounter;

    // argümanlar bitene kadar yazdır
    // 1'den başlatmamızın nedeni ise konsol da ilk programı
    // çalıştıracağımız için programın çalıştırmasını argümandan
    // saymasını istemiyoruz, bu yüzden 1'den başlatıyoruz
    for(argcounter = 1; !NULLER(argv[argcounter]); argcounter++)
    {
        printf("%d) Arguman: %s\n", argcounter, argv[argcounter]);
    }
}