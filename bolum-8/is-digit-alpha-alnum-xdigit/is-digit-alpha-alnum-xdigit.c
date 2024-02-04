/*
* ===================
* Yazan: Slav3rsn1x
* Dil: C
* ===================
*/

// Kütüphaneler
#include <stdio.h>
#include <ctype.h>

// Fonksiyon
int main(void)
{
    // isdigit (rakam ?)
    printf("%s\n%s%s\n%s%s\n\n", "isdigit fonksiyonu sonucu: " ,
    isdigit('8') ? "8 is a " : "8 is not a ", "digit",
    isdigit('#') ? "# is a " : "# is not a ", "digit");

    // isalpha (karakter ?)
    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "isalpha fonksiyonu sonucu: ",
    isalpha('A') ? "A is a ": "A is not a ", "letter",
    isalpha('b') ? "b is a " : "b is not a ", "letter",
    isalpha('&') ? "& is a " : "& is not a ", "letter",
    isalpha('4') ? "4 is a " : "4 is not a ", "letter");

    // alnum (karakter, rakam ?)
    printf("%s\n%s%s\n%s%s\n%s%s\n\n", "isalnum fonksiyonu sonucu: ",
    isalnum('A') ? "A is a " : "A is not a ", "digit or letter",
    isalnum('8') ? "8 is a " : "8 is not a ", "digit or letter",
    isalnum('#') ? "# is a " : "# is not a ", "digit or letter");

    // isxdigit (hexadecimal : onaltılık ?)
    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n", "isxdigit fonksiyonu sonucu: ",
    isxdigit('F') ? "F is a " : "F is not a ", "hexadecimal digit",
    isxdigit('J') ? "J is a " : "J is not a ", "hexadecimal digit",
    isxdigit('7') ? "7 is a " : "7 is not a ", "hexadecimal digit",
    isxdigit('$') ? "$ is a " : "$ is not a ", "hexadecimal digit",
    isxdigit('f') ? "f is a " : "f is not a ", "hexadecimal digit");
}