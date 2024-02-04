// S Dizisindeki Elemanlara 2-20 Arası Çift Tamsayılardan Oluşan İlk Değer Ataması
#include <stdio.h>
#define BOYUT 10 // maksimum dizi boyutu

// main fonksiyonu ile program çalışmaya başlar
int main(void)
{
    // dizi boyutu belirtmede sembolik sabit olan BOYUT kullanımı
    int s[BOYUT]; // s dizisi BOYUT adet elemana sahiptir, yani 10 eleman
    size_t j; // sayaç

    for(j = 0; j < BOYUT; j++)
    {
        s[j] = 2 + (2*j);
    } // döngü sonu

    printf("%s%13s\n", "Eleman", "Deger");

    // dizi içeriğinin çizelge biçiminde yazdırılması
    for(j = 0; j < BOYUT; ++j)
    {
        printf("%7u%13d\n", j, s[j]);
    } // döngü sonu
} // main sonu