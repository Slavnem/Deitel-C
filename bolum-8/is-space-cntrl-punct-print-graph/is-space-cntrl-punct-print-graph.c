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
    // isspace (kaçış karakteri)
    printf("%s\n%s%s%s\n%s%s%s\n%s%s\n\n", "isspace fonksiyonu sonucu: ",
    "Newline", isspace('\n') ? " is a " : " is not a ", "whitespace character",
    "Horizontal tab", isspace('\t') ? " is a " : " is not a ", "whitespace character",
    isspace('%') ? "% is a " : "% is not a ", "whitespace character");

    // iscntrl (kontrol karakteri)
    printf("%s\n%s%s%s\n%s%s\n\n", "iscntrl fonksiyonu sonucu: ",
    "Newline", iscntrl('\n') ? " is a " : " is not a ", "control character",
    iscntrl('$') ? "$ is a " : "$ is not a ", "control character");

    // ispunct (noktalama karakter)
    printf("%s\n%s%s\n%s%s\n%s%s\n\n", "ispunct fonksiyonu sonucu: ",
    ispunct(';') ? "; is a " : "; is not a ", "punctuation character",
    ispunct('Y') ? "Y is a " : "Y is not a ", "punctuation character",
    ispunct('#') ? "# is a " : "# is not a ", "punctuation character");

    // isprint (çıktısı gösterilen verilen karakter)
    printf("%s\n%s%s\n%s%s%s\n\n", "isprint fonksiyonu sonucu: ",
    isprint('$') ? "$ is a " : "$ is not a ", "printing character",
    "Alert", isprint('\a') ? " is a " : " is not a ", "printing character");

    // isgraph (yazdırılabilen karakter)
    printf("%s\n%s%s\n%s%s%s\n", "isgraph fonksiyonu sonucu: ",
    isgraph('Q') ? "Q is a " : "Q is not a ", "printing character other than a space",
    "Space", isgraph(' ') ? " is a " : " is not a ", "printing character other than a space");
}