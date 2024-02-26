// Slavnem @2024-02-27
// Ondalıklı Dönüşüm

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    double ddob; // ondalıklı değişken

    scanf("%le", &ddob); printf("Test le: %le\n", ddob);
    scanf("%lf", &ddob); printf("Test lf: %lf\n", ddob);
    scanf("%lg", &ddob); printf("Test lg: %lg\n", ddob);
}