// Slavnem @2024-06-28
// goto Deyimini Kullnarak Yıldız İle Kare Çıktısı Yapmak

#if 0
    ZORUNLU!

    printf("*")
    printf(" ")
    printf("\n")
#endif

// Kütüphaneler
#include <stdio.h>

// Satır sınırı
#ifndef ROW_MAX
#define ROW_MAX 2
#endif

// SÜtun sınırı
#ifndef COL_MAX
#define COL_MAX 5
#endif

// Satır veya Sütun sınırlaması olmak zorunda
#if !defined(ROW_MAX) || !defined(COL_MAX)
#error "Satir ve Sutun Sinirlamasi Olmak Zorunda!"
#endif

// main
int main(void)
{
    // döngü için değişkenler
    int colcounter = 0; // sütun sayacı
    int rowcounter = 0; // satır sayacı

    // en üst ve en alt satır için
    start:
        // en üst satırı sütun sayacı ile oluşturmak
        for(colcounter = 0; colcounter < COL_MAX; colcounter++, printf("*"));
        printf("\n");

    // satir bas ve sonu
    inrow:
        printf("*");
        colcounter = 1; // sütun sayacını başlat

    // sütun için
    incol:
        if(colcounter < COL_MAX - 1)
        {
            printf(" ");
            colcounter++;
            goto incol;
        }

        // satır sonu
        printf("*\n");

        // satır sayacını arttır ve sonraki satıra geç
        rowcounter++;
        if(rowcounter < ROW_MAX - 1)
        {
            goto inrow;
        }

         // en alt satırı sütun sayacı ile oluşturmak
        for (colcounter = 0; colcounter < COL_MAX; colcounter++)
        {
            printf("*");
        }
        printf("\n");
}