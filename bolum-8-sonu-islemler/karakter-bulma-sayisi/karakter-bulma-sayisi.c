// Slavnem
// Karakter Bulma Sayısı
// =====================
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Ön işlemci tanımlamaları
#define SIZE 100
#define CUMLE 5

// Fonksyon tanımları
int bulsay(const char* const, const int);

// main
int main(void)
{
    // belirli bir miktarda cümle girmesini sağlayan dizi
    char metinler[CUMLE][SIZE];
    char harf; // kullanıcıdan arama için isteyeceğimiz harf
    size_t sayac; // cümleleri sırayla kullanmayı sağlayan sayaç

    // kullanıcı metin girmesini sağlamak
    for(sayac = 0; sayac < CUMLE; sayac++)
    {
        // ne istediğimizi anlaması için kullanıcıya çıktı vermek
        printf("[%zu]%s", (sayac + 1), " metin giriniz: ");

        // sıraya göre metini depolama
        fgets(metinler[sayac], SIZE, stdin);
    }

    // kullanıcıdan aranmasını istediği harfi alma
    printf("Bulup saymak istediginiz harfi giriniz: ");
    scanf("%c", &harf);

    // her cümle için harfi bulup sayma
    for(sayac = 0; sayac < CUMLE; sayac++)
    {
        // cümlede seçilen harf kaç kez var çıktı verme
        printf("[%zu] %c%s%d\n",
            (sayac + 1),
            harf,
            " harfi bulunma miktari: ",
            bulsay(metinler[sayac], harf)
        );
    }
}

// bulsay
int bulsay(const char* const metin, const int harf)
{
    int harfsayac = 0; // harfi teker teker sayacak olan sayaç
    char* geciciPtr; // bulunan harfin konumunu geçici olarak tutan değişken

    // başlangıç olarak harfin konumunu vermek
    geciciPtr = strchr(metin, harf);

    // döngü ile harf harf kontrol
    while(geciciPtr != NULL)
    {
        // sayacı 1 arttırmak
        ++harfsayac;

        // metin içinde sonraki harfin konumunu arama
        geciciPtr = strchr((geciciPtr + 1), harf);
    }

    // kaç kez bulunduğunu döndürmek
    return harfsayac;
}