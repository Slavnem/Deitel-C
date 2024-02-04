// Slavnem
// Alfabetik Sıralama
// ==================
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Ön işlemci tanımlamaları
#define SIZE 50

// main
int main(void)
{
    char sehirler[][SIZE] =
    {
        "Kars",
        "Diyarbakir",
        "Istanbul",
        "Balikesir",
        "Antalya",
        "Izmir",
        "Ankara",
        "Hatay",
        "Igdir",
        "Bursa",
        "Trabzon",
        "Rize",
        "Artvin",
        "Canakkale",
        "Corum"
    };

    size_t sayliste; // liste için sayaç
    size_t sayicliste; // liste için iç sayaç
    const size_t size_sehirler = (sizeof(sehirler) / sizeof(sehirler[0])); // dizinin uzunluğu
    char gecici[SIZE]; // geçici olarak metini tutmak

    // döngü ile saymak
    for(sayliste = 0; sayliste < size_sehirler; sayliste++)
    {
        for(sayicliste = (sayliste + 1); sayicliste < (size_sehirler); sayicliste++)
        {
            // geçici metin kontrol edilen metinden büyükse
            if(strcmp(sehirler[sayliste], sehirler[sayicliste]) > 0)
            {
                // geçici değişken de eski metinin kopyasını tutup
                // eski metinin konumuna yeni metini kopyalayıp
                // yeni metinin konumuna eskiyi kopyalama
                strcpy(gecici, sehirler[sayliste]);
                strcpy(sehirler[sayliste], sehirler[sayicliste]);
                strcpy(sehirler[sayicliste], gecici);
            }
        }
    }

    // sayaç ile sıralı diziyi çıktı verme
    for(sayliste = 0; sayliste < size_sehirler; sayliste++)
    {
        printf("[%02zu] %s\n", (sayliste + 1), sehirler[sayliste]);
    }
}
