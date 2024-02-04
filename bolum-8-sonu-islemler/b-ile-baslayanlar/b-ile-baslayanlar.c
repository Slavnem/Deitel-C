// Slavnem
// "b" İle Başlayanlar
// ===================
// Kütüphaneler
#include <stdio.h>

// Ön işlemci tanımları
#define ASCII_b 98

// main
int main(void)
{
    // rastgele metinler
    char* metinler[] =
    {
        "Bugun bakkala gittim",
        "ekmek aldim",
        "bugun kod yazdim",
        "bir daha kod yazdim",
        "gunu sonlandirdim"
    };

    // toplam metin boyutu
    const size_t size_metinler = (sizeof(metinler) / sizeof(metinler[0]));
    size_t saymetin; // metin çıktıları için sayaç

    // döngü ile metinleri almak
    for(saymetin = 0; saymetin < size_metinler; saymetin++)
    {
        // metinin başı "b" harfi ile başlıyorsa
        if(metinler[saymetin][0] == ASCII_b)
            printf("%s\n", metinler[saymetin]);
    }
}