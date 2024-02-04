// HİSTOGRAM GRAFİĞİ
#include <stdio.h>
#define BOYUT 10

// program main fonksiyonu ile başlar
int main(void)
{
    // n dizisi için başlangıç değeri atama listesi kullanımı
    int n[BOYUT] = { 19, 3, 15, 7, 11, 9, 13, 5, 17, 1 };
    size_t i; // dizi elemanları için dıştaki for döngüsü sayacı
    int j; // her histogram sütunundaki yıldızları sayan iç for döngüsü sayacı

    printf("%s%13s%17s\n", "Eleman", "Deger", "Histogram");

    // n dizisindeki her eleman için histogram grafiğine sütun yazdırma
    for(i = 0; i < BOYUT; i++)
    {
        printf("%7u%13d ", i, n[i]);

        // sütun çizimi
        for(j = 1; j <= n[i]; j++)
        {
            printf("%c", '*');
        } // içerideki döngü sonu

        puts(""); // histogram grafiği sonu
    } // dış döngü sonu
} // main sonu