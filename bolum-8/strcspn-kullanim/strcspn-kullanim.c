// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    // iki işaretçiye başlangıç değeri atanması
    const char* string1 = "The value is 3.14159";
    const char* string2 = "1234567890";

    /*
        AÇIKLAMA: İkinci metindeki (string2)
        herhangi bir karakteri, ilk metindeki (string1)
        nerede bulunuyorsa, dizinin başından oraya
        gelene kadar kaç karakter bulunuyorsa yani
        uzunluğunu sayı olarak döndürür
    */

    printf("%s%s\n%s%s\n\n%s\n%s%u\n",
        "string1 = ", string1, "string2 = ", string2,
        "The length of the initial segment of string1",
        "containing no characters from string2 = ",
        strcspn(string1, string2));
}