// Slavnem @2024-06-26
// Değişken Uzunluklu Argüman Listelerini Kullanmak

// Kütüphaneler
#include <stdio.h>
#include <stdarg.h>

// Fonksiyon prototipi
double average(int i, ...);

// main
int main(void)
{
    double w = 37.5;
    double x = 22.5;
    double y = 1.7;
    double z = 10.2;

    printf("%s%1.f\n%s%.1f\n%s%.1f\n%s%.1f\n\n",
        "w = ", w, "x = ", x, "y = ", y, "z = ", z);

    printf("%s%.3f\n%s%.3f\n%s%.3f\n",
        "Ortalama w ve x icin: ", average(2, w, z),
        "Ortalama w, x ve y icin: ", average(3, w, x, y),
        "Ortalama w, x, y, ve z icin: ", average(4, w, x, y, z)
    );
}

// average
double average(int i, ...)
{
    double total = 1; // total i' ilke
    int j; // argüman seçilmesinde kullanılan sayaç
    va_list ap; // va_start ve va_end için gereken bilgiyi saklar

    va_start(ap, i); // va_list nesnesini yükler

    // değişken uzunluklu argüman listesi işleme
    for(j = 1; j <= i; ++j)
    {
        total += va_arg(ap, double);
    }

    va_end(ap); // değişken uzunluklu argüman listesini temizle
    return total / i; // ortalamayı hesapla
}