// Slavnem @2024-02-27
// Tüm Belirteçler

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    // değişkenler
    int inum;
    double ddob;

    // değer al çıktı ver
    // satır satır okunması için böyle yaptım
    scanf("%d", &inum); printf("test: %d\n", inum);
    scanf("%#o", &inum); printf("test: %d\n", inum);
    scanf("%X", &inum); printf("test: %d\n", inum);
    scanf("%i", &inum); printf("test: %d\n", inum);
    scanf("%lf", &ddob); printf("test: %+.2e\n", ddob);
    scanf("%lf", &ddob); printf("test: %0.2g\n", ddob);
    scanf("%lf", &ddob); printf("test: %-.3f\n", ddob);
}