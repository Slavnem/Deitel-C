// Slavnem
// Piglatin

// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Ön işlemci tanımlamaları
#define SIZE 100

// Fonksiyon tanımı
void printLatinWord(char* ptr);

// main
int main(void)
{
    char metin[SIZE]; // kullanıcıdan alacağımız metin
    char* ptr; // geçici olarak kelime tutucu

    // kullanıcıdan metin almak
    puts("Bir metin giriniz: ");
    fgets(metin, SIZE, stdin);

    // satır sonu karakterlerini silme
    metin[strcspn(metin, "\n")] = '\0';

    // metinin ilk kelimesiniden başlama
    ptr = strtok(metin, " ");

    // yazıları çıktı verme
    printLatinWord(ptr);
}

// printLatinWord
void printLatinWord(char* ptr)
{
    char harf; // geçici olarak harfi tutacak
    const char* const kelime = "ya";
    char metin[SIZE];

    // devamında kelime olmayana kadar dönsün
    while(ptr != NULL)
    {
        // metinin ilk harfini geçici olarak saklama
        harf = ptr[0];

        // metini başından sonraki kısımı başa atama
        memmove(ptr, &ptr[1], strlen(ptr));

        // metinin son harfini geçici olarak
        // sakladığıız harf ile yeniden düzenleme
        memset(&ptr[strlen(ptr)], harf, 1);

        // kelimeleri diziye depolamak
        sprintf(metin, "%s%s ", ptr, kelime);

        // depolanmış metini çıktı vermek
        printf("%s", metin);

        // parçalamaya devam etmek
        ptr = strtok(NULL, " ");
    }

    // boş satır
    puts("");
}