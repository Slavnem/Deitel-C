// Slavnem
// Değişik Formatta Tarih
// ======================
// Kütüphaneler
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ön işlemci tanımları
#define SIZE 100

// Fonksiyon tanımı
void tarihformat(const char* const[], const size_t* const, char*, char*);

// main
int main(void)
{
    // ayları tutan dizi
    static const char* const aylar[] =
    {
        "Ocak", "Subat", "Mart", "Nisan",
        "Mayis", "Haziran", "Temmuz", "Agustos",
        "Eylul", "Ekim", "Kasim", "Aralik"
    };

    char tarih[] = "07/21/2003"; // tarih
    char metin[SIZE]; // metini tutmak

    // ayların tutulduğu dizinin uzunluğu
    const size_t size_aylar = (sizeof(aylar) / sizeof(aylar[0]));

    // eski formatlı metini alıp yenileyip kaydetmek
    tarihformat(aylar, &size_aylar, tarih, metin);

    // yeni formatla çıktı vermek
    printf("%s%s\n", "Yeni Format: ", (metin));
}

// tarihformat
void tarihformat(const char* const ay[], const size_t* const size_ay, char* tarih, char* kaydet)
{
    char* kelime; // metnin parçalanmış halini geçici olarak tutacak
    unsigned long sayi; // kelimeyi sayıya çevirmek için

    // ilk kelimeyi parçalamak
    kelime = strtok(tarih, "/");

    // ilk kelime yok
    if(kelime == NULL)
    {
        printf("%s\n", "Ilk kelime ayirmasi bos");
        return;
    }

    // ilk kelimeyi sayıya çevirmek (ay için)
    sayi = strtoul(kelime, NULL, 0);

    // ay listesinden büyük
    if(sayi <= 0 || sayi >= *size_ay)
    {
        printf("%s%lu\n", "Alinan ay numarasi gecersiz: ", (sayi));
        return;
    }

    // ay bilgisini metine eklemek
    strcat(kaydet, ay[(sayi - 1)]);
    strcat(kaydet, " "); // boşluk eklemek

    // kelimeyi parçalayıp gün bilgisini almak
    kelime = strtok(NULL, "/");

    // gun bilgisi yok
    if(kelime == NULL)
    {
        printf("%s\n", "Gun bilgisi kelime ayirmasi bos");
        return;
    }

    // gün bilgisini metine eklemek
    strcat(kaydet, kelime);
    strcat(kaydet, ","); // virgül eklemek

    // kelimeyi parçalayıp yılı almak
    kelime = strtok(NULL, "/");

    // yil bilgisi yok
    if(kelime == NULL)
    {
        printf("%s\n", "Yil bilgisi kelime ayirmasi bos");
        return;
    }

    // yıl bilgisini eklemek
    strcat(kaydet, kelime);
    strcat(kaydet, "'dir"); // sonlandirmak

    // fonksiyonu boş döndürüp işi bitirmek
    return;
}