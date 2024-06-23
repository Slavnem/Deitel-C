// Slavnem @2024-06-23
// Tamsayı Dizisini Ön Tanımlama İle Çıktı Vermek

// Kütüphaneler
#include <stdio.h>

// Dizi boyutunu belirleme
#ifdef SIZEARRAY
#undef SIZEARRAY
#endif

#define SIZEARRAY(array) (sizeof(array) / sizeof(array[0]))

// Tamsayı dizini çıktı vermek için
#ifdef PRINTARRAY
#undef PRINTARRAY
#endif

#define PRINTARRAY(array, x) for(int i = 0; i < x; i++) { printf("%2d) %-3d\n", (i + 1), array[i]); }

// main
int main(void)
{
    // tamsayı dizisi
    int iarray[] = {
        1, 3, 2, 4, 8,
        6, 9, 7, 5, 0
    };

    // diziyi çıktı vermek
    PRINTARRAY(iarray, SIZEARRAY(iarray));
}