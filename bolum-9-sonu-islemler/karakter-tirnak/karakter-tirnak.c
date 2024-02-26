// Slavnem @2024-02-27
// Karakter Tırnak

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    char s[4]; // karakterleri tutacak olan dizi (suzy)

    // suzy kelimesini 'suzy' veya "suzy"
    // yerine suzy olarak almak

    scanf("%*[\'\"]%4s", s); // metin girdisi almak
    printf("%s\n", s); // girdiyi çıktı vermek
}