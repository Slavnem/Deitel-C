// Slavnem @2024-04-07
// Alıştırmalar

// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Yapı Tanımlamaları
typedef struct
{
    char kisimAdi[30];
    int kisimNumarasi;
    float price;
    int stok;
    int reorder;
} yapiBir;

typedef union
{
    char c;
    short s;
    long b;
    float f;
    double d;
} unionBir;

typedef struct
{
    char ulke[3];
    char sehir[20];
    char sokakAdresi[25];
    char postaKodu[6];
} yapiKonum;

typedef struct
{
    char ad[15];
    char soyad[15];
    yapiKonum EvAdresi;
} yapiOgrenci;

typedef struct
{
    int a: 1;
    int b: 1;
    int c: 1;
    int d: 1;
    int e: 1;
    int f: 1;
    int g: 1;
    int h: 1;
    int i: 1;
    int j: 1;
    int k: 1;
    int l: 1;
    int m: 1;
    int n: 1;
    int o: 1;
    int p: 1;
} yapiBitHarf;

// main
int main(void)
{
    // Ypaıları değişken olarak oluşturmak
    yapiBir srctIlk;
    yapiKonum srctKonum;
    yapiOgrenci srctOgrenci;
    yapiBitHarf srctBit;

    // Normal yapıya direk atama var fakat
    // bir yapı içinde başka bir yapı oluşturulduğunda
    // c dili bellek güvenliği için direk atama yapmaz
    // memcpy, strcpy tarzı fonksiyonlar ile bunu yaparız
    // aksi halde yapılabilir fakat karmaşık olabilir
    memcpy(srctOgrenci.EvAdresi.ulke, "tur", sizeof(srctOgrenci.EvAdresi.ulke));

    // test çıktısı
    printf("test: %s\n", srctOgrenci.EvAdresi.ulke);
}