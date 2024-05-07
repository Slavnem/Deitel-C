// Slavnem @2024-05-07
// Yapı Üyelerine Erişme

// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Yapı Tanımlamaları
typedef struct
{
    char ad[20];
    char soyad[20];
    char musteriNumarasi[11];
    char personelNumarasi[11];
    char personelAdres[50];
    char personelSehir[20];
    char personelUlke[10];
    char personelPostakodu[5];
} musteriKaydi;

// main
int main(void)
{
    // yapı oluşturulması
    musteriKaydi customer;
    musteriKaydi *customerPtr = &customer;

    // yapıya değer atamaları
    memcpy((*customerPtr).ad, "isim", 4);
    memcpy(customerPtr->soyad, "soyad", 5);

    // test çıktısı
    printf("ad: %s\n", (*customerPtr).ad);
    printf("soyad: %s\n\n", customerPtr->soyad);

    printf("boyut customer: %u\n", sizeof(customer));
    printf("boyut customerPtr: %u\n", sizeof(customerPtr));
}