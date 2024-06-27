// Slavnem @2024-06-27
// Ürün Hesaplama

// Kütüphaneler
#include <stdio.h>
#include <stdarg.h>

// Dizi boyutu hesaplayıcı
#ifdef SSIZEARR
#undef SSIZEARR
#endif

#define SSIZEARR(array) (sizeof(array) / sizeof(array[0]))

// Çıktı verici
#ifdef PRINTER
#undef PRINTER
#endif

#define PRINTER(x) (printf("%.2f\n", x))

// Dizi çıktı verici
#ifdef PRINTARR
#undef PRINTARR
#endif

// Çıktı verici olmak zorunda
#ifndef PRINTER
#error "Çıktı Verici Olmak Zorunda!"
#endif

// SSIZEARR olmak zorunda, dizi boyutu hesaplamak için
#ifndef SSIZEARR
#error "Dizi Boyutu Hesaplayıcısı Olmak Zorunda!"
#endif

#define PRINTARR(array) { \
    int sizearr = SSIZEARR(array); \
    for(int i = 0; i < sizearr; i++) { PRINTER(array[i]); } \
}

// Dizi çıktı verici yoksa hata versin
#ifndef PRINTARR
#error "Dizi Çıktı Verici Olmak Zorunda!"
#endif

// Değişken isimlendirmeleri
typedef unsigned int uint;

// Fonksiyon prototipi
static double product(int argi, ...);

// main
int main(void)
{
    // ürün fiyatlarını tutan liste
    double urunler[] = {
        3.2, 5.8, 6.9, 21.5, 38.0,
        23.3, 17.8, 34.6, 59.1, 25.76
    };

    // ürün fiyatlarını çıktı ver
    PRINTARR(urunler);

    // ürünlerin fiyatını hesaplat
    printf("Toplam Fiyat: %.2lf\n",
        product(
            SSIZEARR(urunler),
            urunler[0], urunler[1], urunler[2], urunler[3], urunler[4],
            urunler[5], urunler[6], urunler[7], urunler[8], urunler[9]
        )
    );
}

// product
static double product(int argi, ...)
{
    double total = 0; // toplam fiyat
    uint counter; // argüman sayısı için sayaç
    
    va_list valist; // argüman listesi

    // argüman listesini başlat
    va_start(valist, argi);

    for(counter = 1; counter <= argi; counter++)
    {
        // argüman değerini toplam değere ekle
        total += va_arg(valist, double);
    }

    // argüman listesini temizle
    va_end(valist);

    // sonucu döndür
    return total;
}