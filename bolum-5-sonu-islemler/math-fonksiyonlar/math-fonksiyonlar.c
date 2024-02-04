// MATH.H FONKSİYONLARI
#include <stdio.h>
#include <math.h>

int main(void)
{
    // karekök hesaplar ve çıktısını gösterir
    printf("sqrt(%.1f) = %.1f\n", 900.0, sqrt(900.0));
    printf("sqrt(%.1f) = %.1f\n", 9.0, sqrt(9.0));

    // e üzeri x üssel fonksiyonunu hesaplar ve çıktısını gösterir
    printf("exp(%.1f) = %.1f\n", 1.0, exp(1.0));
    printf("exp(%.1f) = %.1f\n", 2.0, exp(2.0));

    // logaritma (e tabanında) hesaplar ve çıktısını gösterir
    printf("log(%.1f) = %.1f\n", 2.718282, log(2.718282));
    printf("log(%.1f) = %.1f\n", 7.389056, log(7.389056));

    // logaritma (10 tabanında) hesaplar ve çıktısını gösterir
    printf("log10(%.1f) = %.1f\n", 1.0, log10(1.0));
    printf("log10(%.1f) = %.1f\n", 10.0, log10(10.0));
    printf("log10(%.1f) = %.1f\n", 100.0, log10(100.0));

    // mutlak değer hesaplar ve çıktısını gösterir
    printf("fabs(%.1f) = %.1f\n", 9.2, fabs(9.2));
    printf("fabs(%.1f) = %.1f\n", 0.0, fabs(0.0));
    printf("fabs(%.1f) = %.1f\n", -13.5, fabs(-13.5));

    // ceil(x)i hesaplar ve çıktısını gösterir
    printf("ceil(%.1f) = %.1f\n", 9.2, ceil(9.2));
    printf("ceil(%.1f) = %.1f\n", -9.8, ceil(9.8));

    // floor(x)i hesaplar ve çıktısını gösterir
    printf("floor(%.1f) = %.1f\n", 9.2, floor(9.2));
    printf("floor(%.1f) = %.1f\n", -9.8, floor(-9.8));

    // pow(x, y) hesaplar ve çıktısını gösterir
    printf("pow(%.1f, %1.f) = %.1f\n", 2.0, 7.0, pow(2.0, 7.0));
    printf("pow(%.1f, %1.f) = %.1f\n", 9.0, 0.5, pow(9.0, 0.5));

    // fmow(x, y) hesaplar ve çıktısını gösterir
    printf("fmod(%.3f/%.3f) = %.3f\n", 13.657, 2.333, fmod(13.657, 2.333));

    // sin(x)i hesaplar ve çıktısını alır
    printf("sin(%.1f) = %.1f\n", 0.0, sin(0.0));

    // cos(x)i hesaplar ve çıktısını alır
    printf("cos(%.1f) = %.1f\n", 0.0, cos(0.0));

    // tan(x)i hesaplar ve çıktısını alır
    printf("tan(%.1f) = %.1f\n", 0.0, tan(0.0));
}