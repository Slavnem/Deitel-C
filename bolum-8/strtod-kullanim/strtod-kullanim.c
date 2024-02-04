/*
* ===================
* Yazan: Slav3rsn1x
* Dil: C
* ===================
*/

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

// Fonksiyon
int main(void)
{
    // karakter dizini işaretçisine başlangıç değeri tanımlanması
    const char* string = "51.2% are admitted"; // karakter dizinine ilk değeri atanır

    double d; // dönüştürülmüş karakter dizinini tutacak değişken tanımlanır
    char* stringPtr; // char türünde işaretçi tanımlanır

    d = strtod(string, &stringPtr);

    printf("The string \"%s\" is converted to the\n", string);
    printf("double value %.2f and the string \"%s\"\n", d, stringPtr);
}