// Slavnem @2024-02-26
// Tarama Kümesi

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    char z[9]; // z dizisinin tanımlanması

    printf("%s", "Metin giriniz: ");
    scanf("%8[aeiou]", z); // karakter kümesi aranması

    printf("Girilen metin \"%s\"\n", z);
}