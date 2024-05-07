// Slavnem @2024-05-07
// Unsigned Int Düz Ve Tersini Doğrulama

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

// Ön İşlemci Tanımlamalar
#define SIZE_BUFFER 20

// Fonksiyon Tanımları
int converseBits(const unsigned int const*, const unsigned int const*);

// main
int main(void)
{
    unsigned int valueBase; // düz değer
    unsigned int valueReverse; // ters değer
    unsigned int tempvalue; // geçici değer

    char buffer[SIZE_BUFFER]; // geçici metin tutan değişken

    // doğru değer girilene kadar al
    do
    {
        // kullanıcıdan metin alıyoruz
        printf("Pozitif temel deger giriniz: ");
        fgets(buffer, (sizeof(buffer) - 1), stdin);

        // sayıyı 10'luk sisteme göre çeviriyoruz
        tempvalue = (unsigned int)strtoul(buffer, NULL, 0);
    } while (tempvalue <= 0);

    // veri başarılı, geçici değeri depoluyoruz
    valueBase = tempvalue;
    
    // doğru değer girilene kadar al
    do
    {
        // kullanıcıdan metin alıyoruz
        printf("Pozitif ters deger giriniz: ");
        fgets(buffer, (sizeof(buffer) - 1), stdin);

        // sayıyı 10'luk sisteme göre çeviriyoruz
        tempvalue = (unsigned int)strtoul(buffer, NULL, 0);
    } while (tempvalue <= 0);

    // veri başarılı, geçici değeri depoluyoruz
    valueReverse = tempvalue;

    // değer karşılaştırmasını geçici değere kaydediyoruz
    // doğru ya da yanlış değer döndüren bir fonksiyona sahipiz
    tempvalue = converseBits(&valueBase, &valueReverse);
}

// converseBits
int converseBits(const unsigned int const* argBaseValue, const unsigned int const* argReverseValue)
{
    // ana verinin tersini alıyoruz ve ters metinle karşılaştırıyoruz
    const unsigned int const baseReverse = ~(*argBaseValue);
    const unsigned int const verifyReverse = (baseReverse == *argReverseValue);

    // düz ve ters metinin çıktısını, eşleşip eşleşmediğini
    // ve gerçek ters değerini çıktı veriyoruz
    printf("%u ters %u %s\n",
        (*argBaseValue),
        (*argReverseValue),
        (verifyReverse) ? "dogrudur" : "degildir"
    );

    // temel ve ters değer çıktısı
    printf("%u ters: %u\n", (*argBaseValue), baseReverse);
}