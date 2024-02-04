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
    const char* string = "1234567abc"; // karakter dizini işaretçisine başlangıç değeri atama
    unsigned long int x; // dönüştürülmüş diziyi tutması için değişken tanımlama
    char* remainderPtr; // char türünde işaretçi tanımlama

    x = strtoul(string, &remainderPtr, 0);

    printf("%s\"%s\"\n%s%lu\n%s\"%s\"\n%s%lu\n",
    "The original string is ", string,
    "The converted value is ", x,
    "The remainder of the original string is ", remainderPtr,
    "The converted value minus 567 is ", (x - 567));
}