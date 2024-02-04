// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Ön işlemci tanımları
#define SIZE 20

// main
int main(void)
{
    // kullanıcı girdisini tutacak olan diziler
    char s1[SIZE];
    char s2[SIZE];
    int uzunluk; // karsilastirma icin istenen uzunluk
    int scmp; // dizi karşılaştırma sounucu tutacak olan dizi

    // kullanıcıdan metin istemek ve satır olarak almak
    puts("\nBir metin giriniz: ");
    fgets(s1, SIZE, stdin);

    // diğer bir metini istemek
    puts("\nBir metin daha giriniz: ");
    fgets(s2, SIZE, stdin);

    // uzunluk isteme
    puts("\nDizilerin karsilastirilicagi uzunlugu giriniz: ");
    scanf("%d", &uzunluk);

    // metinleri karşılaştırmak
    // eğer belirli sınır içinde değilse dizilerin tamamını
    // normal girilmişse eğer istenen kısıma kadarını kontrol etsin
    scmp = strncmp(s1, s2, ((uzunluk < 0 || uzunluk > SIZE) ? SIZE : uzunluk));

    // sonucu çıktı vermek
    if(scmp > 0)
        puts("\ns1, s2'den buyuk");
    else if(scmp < 0)
        puts("\ns2, s1'den buyuk");
    else
        puts("\ns1 esittir s2");
}