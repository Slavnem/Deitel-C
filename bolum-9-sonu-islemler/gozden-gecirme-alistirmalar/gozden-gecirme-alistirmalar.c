// Slavnem @2024-02-26
// Gözden Geçirme Alıştırmalar

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    // 10 basamak genişliğinde sağa yaslanmış 1234
    printf("%+10d\n", 1234);

    // Üssel gösterimle işaretli olarak 3 basamak
    // duyarlılığa sahip 123.456789 yazdırma
    printf("%+.3le\n", 123.456789);

    // Double türündeki bir değeri sayı
    // değişkenine alma
    double dob;
    scanf("%lf", &dob);

    // 0 ile başlayacak şekilde 100 sayısını
    // sekizlik sistemde yazdırma
    printf("%#o\n", 100);

    // Bir karakter dizinini karakter dizisi tutan
    // karakter dizinine yazdırın
    char* string;
    scanf("%s", string);

    // Sayı olmayan bir karakterle karşılaşıncaya kadar
    // n dizisine karakter yazdırma
    char* n;
    scanf("%[0123456789]", n);

    // x ve y değişkenlerini alan genişliği ve duyarlığı
    // belirtecek şekilde kullanıp 87.4573 değerini yazdırma
    int x = 1;
    int y = 1;
    printf("%*.*f", x, y, 87.4573);

    // 3.5% biçiminde bir değer alın. Bu yüzde değerini
    // float türündeki yüzde değişkeninde depolayın ve
    // % işaretini kaldırın. Atama bastırma karakter kullanmayın
    float deger;
    scanf("%f%%", &deger);

    // 3.333333 sayısını long double türünde ve işaretli (+ veya -)
    // olarak 3 duyarlıkla, 20 karakterli bir alana yazdırın
    printf("%+20.3lf\n", 3.333333);
}