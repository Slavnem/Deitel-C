// Slavnem @2024-04-24
// Birlik (Union) Veri Tipi

// Kütüphaneler
#include <stdio.h>

// number birliğinin tanımlanması
union number
{
    int x;
    double y;
};

// main
int main(void)
{
    union number value; // birlik değişkeni tanımlama

    value.x = 100; // birlik'in içerisinie bir tamsayı atamak
    printf("%s\n%s\n%s\n %d\n\n%s\n %f\n\n\n",
        "Put 100 in the integer member",
        "and print both members.",
        "int: ", value.x,
        "double: ", value.y);

    value.y = 100.0; // aynı birlik'e double değer atama
    printf("%s\n%s\n%s\n %d\n\n%s\n %f\n",
        "Put 100.0 in the floating member",
        "and print both members.",
        "int: ", value.x,
        "double: ", value.y);
}