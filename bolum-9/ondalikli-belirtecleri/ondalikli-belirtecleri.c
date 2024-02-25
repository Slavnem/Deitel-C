// Slavnem @2024-02-25
// Ondalıklı Belirteçleri

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    printf("%e\n", 1234567.89);
    printf("%e\n", +1234567.89); // + işareti yazdırılmaz
    printf("%e\n", -1234567.89); // - işareti yazdırılır
    printf("%E\n", 1234567.89);
    printf("%f\n", 1234567.89);
    printf("%g\n", 1234567.89);
    printf("%G\n", 1234567.89);
}