// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

// Ön işlemci tanımları
#define SIZE 4

// main
int main(void)
{
    char s[SIZE]; // metin girilmesini tutacak
    long sayi = 0; // çevirilen sayıyı tutup toplanacak olan değişken
    int i; // sayaç

    // döngü ile dizi bitene kadar karakterleri toplama
    for(i = 0; i < SIZE; i++)
    {
        // kullanıcıdan çıktı istemek
        printf("[%d] Bir sayi giriniz: ", (i + 1));
        scanf("%4s", s);

        // sayıyı çevirip toplamak
        sayi += strtol(s, NULL, 0);
    }

    // çıktı verme
    printf("\nGirdiginiz karakterlerin toplami: %d\n", sayi);
}