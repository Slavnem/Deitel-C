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
    int scmp; // dizi karşılaştırma sounucu tutacak olan dizi

    // kullanıcıdan metin istemek ve satır olarak almak
    puts("\nBir metin giriniz: ");
    fgets(s1, SIZE, stdin);

    // diğer bir metini istemek
    puts("\nBir metin daha giriniz: ");
    fgets(s2, SIZE, stdin);

    // metinleri karşılaştırmak
    scmp = strcmp(s1, s2);

    // sonucu çıktı vermek
    printf("\ns1 cmp s2: %d\n", scmp);
}