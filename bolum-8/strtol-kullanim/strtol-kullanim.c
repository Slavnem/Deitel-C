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
    const char* string = "-1234567abc"; // işaretçi tanımı

    char* remainderPtr; // char türünde işaretçi oluşturulması
    long x; // dönüştürülmüş diziyi tutmak için değişken tanımı

    x = strtol(string, &remainderPtr, 0);

    printf("%s \"%s\"\n%s%ld\n%s\"%s\"\n%s%ld\n",
    "The original string is ", string,
    "The converted value is ", x,
    "The remainder of the original string is ", remainderPtr,
    "The converted value plus 567 is ", (x + 567));
}