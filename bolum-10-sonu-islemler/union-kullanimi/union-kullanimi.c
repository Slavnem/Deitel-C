// Slavnem @2024-04-26
// Union Kullanımı

// Kütüphaneler
#include <stdio.h>

// Union Yapılar
union Multion
{
    char c;
    short s;
    int i;
    long b;
};

// İsimlendirme
typedef union Multion MultiUnio;

// main
int main(void)
{
    MultiUnio coklUnion; // çoklu değişken içeren union

    coklUnion.c = __SCHAR_MAX__; // char
    printf("char: %c | short: %hd | int: %d | long: %ld\n", coklUnion.c, coklUnion.c, coklUnion.c, coklUnion.c);

    coklUnion.s = __SHRT_MAX__; // short
    printf("char: %c | short: %hd | int: %d | long: %ld\n", coklUnion.s, coklUnion.s, coklUnion.s, coklUnion.s);

    coklUnion.i = __INT_MAX__; // int
    printf("char: %c | short: %hd | int: %d | long: %ld\n", coklUnion.i, coklUnion.i, coklUnion.i, coklUnion.i);

    coklUnion.b = __LONG_MAX__; // long
    printf("char: %c | short: %hd | int: %d | long: %ld\n", coklUnion.b, coklUnion.b, coklUnion.b, coklUnion.b);
}