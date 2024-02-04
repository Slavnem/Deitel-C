// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    // iki işaretçiye başlangıç değeri atanması
    const char* string1 = "The value is 3.14159";
    const char* string2 = "aehi lsTuv";

    /*
        AÇIKLAMA: İkinci metindeki (string2) tüm
        karakterleri ilk metinde bulur ve son
        olarak bulduğu konumun uzunluğunu döndürür
    */

    printf("%s%s\n%s%s\n\n%s\n%s%u\n",
        "string1 = ", string1, "string 2 = ", string2,
        "The length of the initial segment of string1",
        "containing only characters from string2 = ",
        strspn(string1, string2));
}