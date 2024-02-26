// Slavnem @2024-02-27
// Çeşitli Duyarlılık

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    // ondalıklı sayı
    double num = 9876.12345;

    // sırayla duyarlılıklar
    printf("1: %.1g\n", num);
    printf("2: %.2g\n", num);
    printf("3: %.3g\n", num);
    printf("4: %.4g\n", num);
    printf("5: %.5g\n", num);
    printf("6: %.6g\n", num);
    printf("7: %.7g\n", num);
    printf("8: %.8g\n", num);
    printf("9: %.9g\n", num);
}