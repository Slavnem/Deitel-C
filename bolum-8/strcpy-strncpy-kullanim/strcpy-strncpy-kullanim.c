////////////////////////
// Yazan: Slavnem
// Dil: C
////////////////////////

// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Ön işlemci tanımları
#define SIZE1 25
#define SIZE2 15

// main
int main(void)
{
    char x[] = "Happy Birthday to You"; // x karakter dizisine başlangıç değeri atama
    char y[SIZE1]; // y karakter dizisi oluşturma
    char z[SIZE2]; // z karakter dizisi oluşturma

    // x içeriğini y'ye kopyalama
    printf("%s%s\n%s%s\n",
    "The string in array x is: ", x,
    "The string in array y is: ", strcpy(y, x));

    // x'in ilk 14 karakterini z'ye kopyalama
    // null karakteri kopyalanamaz
    strncpy(z, x, SIZE2 - 1);

    z[SIZE2 - 1] = '\0'; // z karakter dizisinin sonlandırılması
    printf("The string in array z is: %s\n", z);
}