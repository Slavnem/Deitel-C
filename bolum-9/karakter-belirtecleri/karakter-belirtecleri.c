// Slavnem @2024-02-25
// Karakter Belirteçleri

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    char character = 'A'; // character değişkenine başlangıç değeri atanması
    char string[] = "This is a string"; // diziye başlangıç değeri atanması
    const char* stringPtr = "This is also a string"; // char türünde işaretçi

    printf("%c\n", character);
    printf("%s\n", "This is a string");
    printf("%s\n", string);
    printf("%s\n", stringPtr);
}