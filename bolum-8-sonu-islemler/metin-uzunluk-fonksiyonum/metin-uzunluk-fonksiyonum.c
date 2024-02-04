// Slavnem
// Metin Uzunluk Fonksiyonum
// =========================
// Kütüphaneler
#include <stdio.h>

// Ön işlemci tanımları
#define SIZE 100

// Fonksiyon tanımları
size_t mtnbyt(const char*);

// main
int main(void)
{
    // test amaçlı metin
    char metin[SIZE] = "deneme metini";

    // test amaçlı çıktı
    printf("metin uzunluk: %zu\n", mtnbyt(metin));
}

// mtnbyt
size_t mtnbyt(const char* mtn)
{
    // sayaç ile metinin uzunluğunu döndürmek
    size_t count = 0;

    // döngü ile metin sonuna kadar saymak
    // metin sonu gelmemişse sonraki konuma geçsin ve sayacı arttırsın
    for(/* başlangıca gerek yok */; *mtn != '\0'; mtn++, count++);

    // bulduğumuz metin uzunluğunu döndürüyoruz
    return count;
}