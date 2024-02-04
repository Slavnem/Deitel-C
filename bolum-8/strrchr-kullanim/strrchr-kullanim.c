// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    // işaretçiye başlangıç değeri atama
    const char* string1 = "A zoo has many animals including zebras";

    int c = 'z'; // aranması istenen karakter

    /*
        AÇIKLAMA: Belirlenen karakterin (z) metindeki (string1)
        en son bulunduğu konumdaki kelime ne ise onu döndür
        yoksa NULL döndür
    */

    printf("%s\n%s'%c'%s\"%s\"\n",
        "The remainder of string1 beginning with the",
        "last occurrence of character ", c,
        " is: ", strrchr(string1, c));
}