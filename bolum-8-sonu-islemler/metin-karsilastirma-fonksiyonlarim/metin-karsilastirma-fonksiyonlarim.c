// Slavnem
// Metin Karşılaştırma Fonksiyonlarım
// ==================================
// Kütüphaneler
#include <stdio.h>

// Ön işlemci tanımları
#define SIZE 100

int mtnfark(const char*, const char*);
int mtnbfark(const char*, const char*, size_t);

// main
int main(void)
{
    // test amaçlı iki tane metin
    char metin[SIZE] = "deneme Metini";
    char yazi[SIZE] = "deneme metini";

    // test amaçlı çıktı
    printf("metin1 fark metin2: %d\n", mtnfark(metin, yazi));
    printf("metin1 fark metin2 boyut 1: %d\n", mtnbfark(metin, yazi, 5));
    printf("metin1 fark metin2 boyut 2: %d\n", mtnbfark(metin, yazi, 10));
    printf("metin2 fark metin1 boyut 1: %d\n", mtnbfark(yazi, metin, 5));
    printf("metin2 fark metin1 boyut 2: %d\n", mtnbfark(yazi, metin, 10));
}

// mtnfark
int mtnfark(const char* mtn1, const char* mtn2)
{
    // 2 metin arasındaki farkı sayı olarak belirleyen sayı
    // otomatik olarak metinler eşittir
    int fark = 0;
    // metin karşılaştırma da farklılık çıkana kadar sayacak
    // hangi konumda farklılık varsa bu sayede konumu döndüreceğiz
    size_t count = 0;

    // Normalde A harfi a harfinden büyüktür
    // fakat ASCII standartlarına göre
    // A harfi 65 numara, a harfi ise 97 numara
    // bu durumda küçük a büyük oluyor
    // bu yüzden büyük küçük farkını
    // ASCII standartına göre yapıyoruz

    // metinlerin sonuna gelinmemişse
    while(*mtn1 != '\0' && *mtn2 != '\0')
    {
        // ilk metin büyükse pozitif
        if(*mtn1 < *mtn2)
        {
            fark = count;
            break;
        }
        // ikinci metin büyükse negatif
        else if(*mtn1 > *mtn2)
        {
            fark = (-1 * count);
            break;
        }

        // fark yok, sayacı arttır
        ++count;

        // sonraki konuma geç
        ++mtn1;
        ++mtn2;
    }

    // farkı döndürmek
    return fark;
}

// mtnbfark
int mtnbfark(const char* mtn1, const char* mtn2, size_t byt)
{
    // 2 metin arasındaki farkı sayı olarak belirleyen sayı
    // otomatik olarak metinler eşittir
    int fark = 0;
    // metin karşılaştırma da farklılık çıkana kadar sayacak
    // hangi konumda farklılık varsa bu sayede konumu döndüreceğiz
    size_t count = 0;
    size_t boyut; // boyut aşılana kadar dönmesini sağlayacak

    // döngü le boyut kadar sayma
    for(boyut = 0; boyut < byt; boyut++)
    {
        // ikisinden birisinin sonuna gelmişse eğer
        // orda döngüyü sonlandırsın
        if(*mtn1 == '\0' || *mtn2 == '\0')
            break;

        // metin sonuna gelmedi işlem devam ediyor
        // ilk metin büyükse pozitif
        if(*mtn1 < *mtn2)
        {
            fark = count;
            break;
        }
        // ikinci metin büyükse negatif
        else if(*mtn1 > *mtn2)
        {
            fark = (-1 * count);
            break;
        }

        // fark yok sayacı arttır
        ++count;

        // sonraki konuma geç
        ++mtn1;
        ++mtn2;
    }

    // farkı döndürmek
    return fark;
}