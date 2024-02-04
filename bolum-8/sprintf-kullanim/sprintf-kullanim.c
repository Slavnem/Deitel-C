////////////////////////////
// Yazan: Slavnem
// Dil: C
////////////////////////////

// Kütüphaneler
#include <stdio.h>

// Ön işlemci tanımları
#define SIZE 80

// main
int main(void)
{
    char s[SIZE]; // char dizisi oluşturulması
    int x; // x tamsayı girdi değeri
    double y; // y ondalıklı girdi değeri

    puts("Enter an integer and double: ");
    scanf("%d%lf", &x, &y);

    sprintf(s, "integer: %6d\ndouble: %8.2lf", x, y);

    printf("%s\n%s\n", "The formatted output stored in array s is: ", s);
}