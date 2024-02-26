// Slavnem @2024-02-26
// Çeşitli Sayı

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    // tam sayıyı ve ondalıklı sayıyı
    // daha az basamakla yazmaya çalışmak
    int x = 12345;
    double y = 1.2345;

    printf("%d\n", x);
    printf("%-.2le\n", y);
}