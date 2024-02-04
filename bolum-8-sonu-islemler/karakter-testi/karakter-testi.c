// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <ctype.h>

// main
int main(void)
{
    char c; // karakter

    // kullanıcıdan değer alma
    printf("Bir karakter giriniz: ");
    scanf("%c", &c);

    // karakter fonksiyonları ile teker teker işlem yapma
    printf("isblank: %d\n", isblank(c));
    printf("isdigit: %d\n", isdigit(c));
    printf("isalpha: %d\n", isalpha(c));
    printf("isalnum: %d\n", isalnum(c));
    printf("isxdigit: %d\n", isxdigit(c));
    printf("islower: %d\n", islower(c));
    printf("isupper: %d\n", isupper(c));
    printf("isspace: %d\n", isspace(c));
    printf("iscntrl: %d\n", iscntrl(c));
    printf("ispunct: %d\n", ispunct(c));
    printf("isprint: %d\n", isprint(c));
    printf("isgraph: %d\n", isgraph(c));
}