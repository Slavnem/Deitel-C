// Dizi gosterimi ve isaretci gosterimi kullanarak karakter dizini kopyalamak
#include <stdio.h>
#define SIZE 10

// ++copy1
void copy1(char * const s1, const char * const s2); // prototip

// ++copy2
void copy2(char *s1, const char *s2); // prototip

// +main
int main(void)
{
    char string1[SIZE]; // string1 dizisini olustur
    char *string2 = "Hello"; // bir karakter dizini isaretcisi olustur
    char string3[SIZE]; // string3 dizisi olustur
    char string4[] = "Good Bye"; // bir karakter dizini isaretcisi olustur

    copy1(string1, string2);
    printf("string1: %s\n", string1);

    copy2(string3, string4);
    printf("string3: %s\n", string3);
}
// -main

// dizi gosterimi kullanarak s2'yi s1'e kopyala
// +copy1
void copy1(char * const s1, const char * const s2)
{
    size_t i; // sayac

    // karakter dizinleri boyunca dongu olustur
    for(i = 0; (s1[i] = s2[i]) != '\0'; ++i); // for blogu sonu
}
// -copy1

// isaretci gosterimi kullanarak s2'yi s1'e kopyala
void copy2(char *s1, const char *s2)
{
    // karakter dizinleri boyunca dongu olustur
    for(; (*s1 = *s2) != '\0'; ++s1, ++s2); // for blogu sonu
}