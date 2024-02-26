// Slavnem @2024-02-26
// Karakterler Okuma

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    char x;
    char y[9];

    printf("%s", "Metin giriniz: ");
    scanf("%c%8s", &x, y);

    puts("Girilen cikti:\n");
    printf("Karakter: \"%c\" ve metin \"%s\"\n", x, y);
}