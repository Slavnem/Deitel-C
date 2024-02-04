// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    const char* s = "This is a string"; // karakter işaretçisine başlangıç değeri atanması

    /*
        AÇIKLAMA: Bir metinin içinde belirlenmiş olan
        bir karakteri arama fakat belirli boyut sınırında.
        Eğer karakter bulunursa, bulunduğu konum ve sonrasını
        metin olarak (char*) döndürmesini sağlama, eğer
        bulunamazsa NULL döndürür
    */

    printf("%s\'%c\'%s\"%s\"\n",
        "The remainder of s after character ", 'r',
        " is found is ", (char*)memchr(s, 'r', 16));
}