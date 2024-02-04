// DİZİ BAŞLANGIÇ ELEMANLARINA SIFIR ATAMA
#include <stdio.h>

int main(void)
{
    int n[10]; // n 10 elemandan oluşan dizisi
    size_t i; // sayaç

    // n dizisindeki elemanlara 0 değeri atama
    for(i = 0; i < 10; i++)
    {
        n[i] = 0; // i. pozisyondaki elemana 0 atama
    } // döngü sonu

    printf("%s%13s\n", "Eleman", "Deger");

    // dizi içeriğini çizelge şeklinde ekrana yazdırma
    for(i = 0; i < 10; i++)
    {
        printf("%7u%13d\n", i, n[i]);
    } // döngü sonu
} // main sonu