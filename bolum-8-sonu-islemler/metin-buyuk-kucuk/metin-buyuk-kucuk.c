// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <ctype.h>

// Ön işlemci tanımları
#define SIZE 100

// main
int main(void)
{
    char s1[SIZE]; // metini tutacak olan dizi
    int i; // sayaç

    // kullanıcıdan metin isteme
    puts("Bir metin giriniz: ");
    fgets(s1, SIZE, stdin);

    // tüm metni başta küçük
    printf("\nkucuk harf: ");

    // harf harf küçültüp çıktı verme
    for(i = 0; i < SIZE; i++)
        putchar(tolower(s1[i]));

    // tüm metni büyük
    printf("buyuk harf: ");

    // harf harf büyültüp çıktı verme
    for(i = 0; i < SIZE; i++)
        putchar(toupper(s1[i]));
}