// Slavnem @2024-02-25
// Değişken Belirteci

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    int* ptr; // int türünde gösterge tanımlama
    int x = 12345; // x'e başlangıç değeri ataması

    ptr = &x; // x'in adresini ptr'ye atama

    printf("The value of ptr is %p\n", ptr);
    printf("The address of x is %p\n\n", &x);

    puts("Printing a %% in a format control string");
}