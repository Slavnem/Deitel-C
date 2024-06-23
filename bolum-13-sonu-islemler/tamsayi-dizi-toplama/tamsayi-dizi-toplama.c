// // Slavnem @2024-06-23
// Tamsayı Dizisini Ön Tanımlama İle Toplama

// Kütüphaneler
#include <stdio.h>

// Dizi boyutunu belirleme
#ifdef SIZEARRAY
#undef SIZEARRAY
#endif

#define SIZEARRAY(array) (sizeof(array) / sizeof(array[0]))

// Tamsayı dizini toplamak için
#ifdef SUMARRAY
#undef SUMARRAY
#endif

#define SUMARRAY(array, x) ({ \
    int sum = 0; \
    for(int i = 0; i < x; i++) { \
        sum += array[i]; } \
    sum; \
})

// main
int main(void)
{
    // tamsayı dizisi
    int iarray[] = {
        1, 3, 2, 4, 8,
        6, 9, 7, 5, 0
    };

    // diziyi çıktı vermek
    printf("Dizi Toplami: %d\n", SUMARRAY(iarray, SIZEARRAY(iarray)));
}