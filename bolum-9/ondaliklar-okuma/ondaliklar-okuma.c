// Slavnem @2024-02-26
// Ondalıklar Okuma

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    double a;
    double b;
    double c;

    puts("Uc tane ondalikli sayi giriniz:");
    scanf("%le%lf%lg", &a, &b, &c);

    puts("\nHere are the numbers entered in plain:");
    puts("Ondalikli gosterimi:\n");
    printf("%f\n%f\n%f\n", a, b, c);
}