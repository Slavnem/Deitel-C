// Slavnem
// Tersten Cümle

// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Ön işlemci tanımlamaları
#define SIZE 100

// Fonksiyon tanımlamaları
void tersten(const char* const);

// main
int main(void)
{
    char metin[SIZE]; // kullanıcıdan metin alacak olan değişken
    char* ptr; // metinin parçalanmış halini geçici olarak tutacak

    // kullanıcıdan metin istemek
    puts("Bir metin giriniz: ");
    fgets(metin, SIZE, stdin);

    // satır sonu karakterlerini silme
    metin[strcspn(metin, "\n")] = '\0';

    // ilk kelimeyi boşlukla ayırmak
    ptr = strtok(metin, " ");

    // eğer metinin devamı varsa dönmeye devam etsin
    // ta ki bitene kadar
    while(ptr != NULL)
    {
        // tersten yazması için fonkiyona gönderiyoruz
        tersten(ptr);

        // metini tekrardan parçalıyoruz
        ptr = strtok(NULL, " ");
    }

    puts(""); // boş satır
}

// tersten
void tersten(const char* const sptr)
{
    int count; // sayaç

    // verilen metinin tersinden başlayarak
    // harf harf çıktı vermek
    // strlen(sptr) - 1 dememizin nedeni ise
    // sonuna \n ekleyeceği için aslında
    // 4 karakter olduğunda 5 diyecek çünkü
    // t e s t \n    olacağından 5 diyecek
    // biz ise bunun 1 eksiğini alarak gerçek
    // karakter sayını baz almış oluyoruz
    for(count = (strlen(sptr) -1); count >= 0; count--)
    {
        // harfi çıktı verme
        putchar(sptr[count]);
    }

    printf(" "); // boşluk koymak
}