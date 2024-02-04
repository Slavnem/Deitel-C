// Slavnem
// Metin Arama

// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Ön işlemci tanımlamaları
#define SIZE 100

// main
int main(void)
{
    char metin[SIZE]; // kullanıcıdan alınacak metin
    char kelime[SIZE]; // aranamak istenen kelimeyi saklayacak
    char* searchPtr; // bulunan kısmın atanacağı değişken

    // kullanıcıdan metin almak
    puts("Bir metin giriniz: ");
    fgets(metin, SIZE, stdin);

    // kullanıcıdan aranacak olan kelimeyi almak
    puts("Aranacak kelimeyi giriniz: ");
    scanf("%s", kelime);

    // satır sonları kısmını silmek
    metin[strcspn(metin, "\n")] = '\0';

    // kelimeyi ilk bulduğu kısımı ata
    searchPtr = strstr(metin, kelime);

    // eğer boş değilse devam etsin
    while(searchPtr != NULL)
    {
        // kelimeyi bulduğu kısım dahil
        // sonrasını çıktı ver
        printf("%s\n", searchPtr);

        // kelimenin tekrar bulunmuş kısmını al
        searchPtr = strstr((searchPtr + 1), kelime);
    }
}