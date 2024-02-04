// Slavnem
// "ed" İle Bitenler
// ===================
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Ön işlemci tanımları
#define ASCII_d 100
#define ASCII_e 101

// main
int main(void)
{
    // rastgele metinler
    char* metinler[] =
    {
        "Bugun bakkala gittim",
        "abine telefon ed",
        "bugun kod yazdim",
        "bir daha kod yazdim",
        "naber veled"
    };

    // toplam metin boyutu
    const size_t size_metinler = (sizeof(metinler) / sizeof(metinler[0]));
    size_t saymetin; // metin çıktıları için sayaç

    // döngü ile metinleri almak
    for(saymetin = 0; saymetin < size_metinler; saymetin++)
    {
        // metinin sonu "ed harfleri ile bitiyorsa
        if(metinler[saymetin][strlen(metinler[saymetin]) - 1] == ASCII_d && metinler[saymetin][strlen(metinler[saymetin]) - 2] == ASCII_e)
            printf("%s\n", metinler[saymetin]);
    }
}