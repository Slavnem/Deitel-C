// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    char x[] = "Home Sweet Home"; // x dizisine başlangıç değeri atama

    /*
        AÇIKLAMA: Belirlenen kısımdan başlayarak belirli boyut dahilinde
        olan veriyi, belirlenen dizinin başına yerleştirmek, bu sayede
        baştakı Home Sweet Home yerine, Sweet Home başa gelir ve Home
        kaydırılarak onlardan sonrasına gelir
    */

    printf("%s%s\n", "The string in array x before memmove is: ", x);
    printf("%s%s\n", "The string in array x after memmove is: ", (char*)memmove(x, &x[5], 10));
}