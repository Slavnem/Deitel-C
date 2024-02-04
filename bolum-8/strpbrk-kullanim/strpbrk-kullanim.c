// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    const char* string1 = "This is a test"; // işaretçiye başlangıç değeri atanması
    const char* string2 = "beware"; // işaretçiye başlangıç değeri atanması

    /*
        AÇIKLAMA: İkinci metindeki (string2) bulunan karakterlerden
        hangisi ilk önce ilk metinde (string1) bulunuyorsa onu döndürür
    */

    printf("%s\"%s\"\n'%c'%s\n\"%s\"\n",
        "Of the characters in ", string2,
        *strpbrk(string1, string2),
        "appears earliest in ", string1);
}