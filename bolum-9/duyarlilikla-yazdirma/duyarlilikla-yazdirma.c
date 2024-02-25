// Slavnem @2024-02-25
// Duyarlılıkla Yazdırma

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    int i = 873; // i ye başlangıç değeri atanması
    double f = 123.94536; // f ye başlangıç değeri atanması
    char s[] = "Happy Birthday"; // s karakter dizisine başlangıç değeri atanması

    puts("Using precision for integers");
    printf("\t%.4d\n\t%.9d\n\n", i, i);

    puts("Using precision for floating point numbers");
    printf("\t%.3f\n\t%.3e\n\t%.3g\n\n", f, f);

    puts("Using precision for string");
    printf("\t%.11s\n", s);
}