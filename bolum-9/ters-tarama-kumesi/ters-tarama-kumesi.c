// Slavnem @2024-02-26
// Ters Tarama Kümesi

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    char z[9];

    printf("%s", "Metin giriniz: ");
    scanf("%8[^aeiou]", z); // ters tarama kümesi

    printf("Girilen metin \"%s\"\n", z);
}