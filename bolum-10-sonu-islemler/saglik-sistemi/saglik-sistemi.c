// Slavnem @2024-05-08
// Sağlık Bilgilerinin Bilgisayar İle Tutulması

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ön İşlemci Tanımlamaları
#define UINT_MAX_BIT (__CHAR_BIT__ * sizeof(unsigned int))

#define GENDER_FEMALE 0
#define GENDER_MALE 1

#define TEXT_GENDER_FEMALE "Disi"
#define TEXT_GENDER_MALE "Erkek"

#define YEAR_NOW 2024

// Yapı Tanımlamaları
typedef struct
{
    char ad[21];
    char soyad[21];
    unsigned int cinsiyet : 1; // 0 = dişi, 1 = erkek
    char dogumtarihi[11]; // ??/??/????
    unsigned int boy: 8; // cm
    float kilo; // kg
    unsigned int: (UINT_MAX_BIT - 9); // bellek hizalama
} SaglikProfili;

typedef struct
{
    unsigned int gun: 5; // gün 5 bit olabilir en fazla (31)
    unsigned int ay: 4; // ay 4 bit olabilir en fazla (12)
    unsigned int yil: 11; // yıl için 11 bit desteği (2024)
    unsigned int yas: 8; // yaş için bit değişkeni (max 150)
    unsigned int: (
        // 64 bit de 4 bayt yer kapladığından ek ihtiyaca gerek yok ama
        // 32 bit de 2 baytdan fazla yer kapladığı için
        // 4 bayt üzerinden değerlendirme yaptırıyoruz
        // bu yüzden 2 ile çarpıyoruz öyle çıkarıyoruz
        (UINT_MAX_BIT - (5+4+11+8)) >= 0 ?
            (UINT_MAX_BIT - (5+4+11+8)):
            ((UINT_MAX_BIT* 2) - (5+4+11+8))
    ); // bellek hizalama
} Tarih;

// Fonksiyon Tanımları
void saglikIndeks(unsigned int const, float const);
void saglikBilgi(const SaglikProfili* const);

// main
int main(void)
{
    // yapı oluştur
    SaglikProfili saglikProfili;

    // veri ata
    memcpy(saglikProfili.ad, "Abdulkadir", 10);
    memcpy(saglikProfili.soyad, "Uzmali", 6);
    memcpy(saglikProfili.dogumtarihi, "23/04/2004", (sizeof(saglikProfili.dogumtarihi) - 1));

    saglikProfili.cinsiyet = GENDER_MALE;
    saglikProfili.boy = 189;
    saglikProfili.kilo = 100.0;

    // çıktı verdirme
    saglikBilgi(&saglikProfili);
}

// saglikIndeks
void saglikIndeks(unsigned int const argBoy, float const argKilo)
{
    // metre olarak boyu hesapla
    float boymetre = ((float)argBoy) / 100;

    // indeks değerini çıktı ver
    printf("Saglik indeksi: %.1f\n", (float)argKilo / (boymetre * boymetre));
}

// saglikBilgi
void saglikBilgi(const SaglikProfili* const argSaglik)
{
    // gün, ay, yıl bilgisini almak
    Tarih dogumTarihi;

    // metini parçalamak için değişken
    char dogum[strlen(argSaglik->dogumtarihi)]; // doğum tarihini tutacak
    memcpy(dogum, argSaglik->dogumtarihi, strlen(argSaglik->dogumtarihi)); // doğum tarihini kopyala
    
    char* parcala = strtok(dogum, "/");

    // parçalara ayırıp doğum tarihini almak
    (dogumTarihi.gun) = (parcala != NULL) ?
        ((unsigned int)strtoul(parcala, NULL, 0)): 0; // sayıya çevir al

    (parcala != NULL) ? (parcala = strtok(NULL, "/")): 0; // sonraki parçayı al

    (dogumTarihi.ay) = (parcala != NULL) ?
        ((unsigned int)strtoul(parcala, NULL, 0)): 0; // sayıya çevir al

    (parcala != NULL) ? (parcala = strtok(NULL, "/")): 0; // sonraki parçayı al

    (dogumTarihi.yil) = (parcala != NULL) ?
        ((unsigned int)strtoul(parcala, NULL, 0)): 0; // sayıya çevir al

    (dogumTarihi.yas) = (YEAR_NOW - dogumTarihi.yil); // yaşı ayarla

    puts("----------"); // boş satır
    printf("Ad Soyad: %s %s\n", (*argSaglik).ad, (*argSaglik).soyad); // isim soyisim
    printf("Dogum Tarihi: %s\n", (*argSaglik).dogumtarihi);
    printf("Yas: %u\n", (dogumTarihi.yas));
    printf("Cinsiyet: %s\n", (*argSaglik).cinsiyet == GENDER_FEMALE ? (TEXT_GENDER_FEMALE) : (TEXT_GENDER_MALE));
    printf("Kilo: %.1f kg\n", (*argSaglik).kilo);
    printf("Boy: %u cm\n", (*argSaglik).boy);
    saglikIndeks((argSaglik->boy), (argSaglik->kilo));
    puts("----------"); // boş satır
}