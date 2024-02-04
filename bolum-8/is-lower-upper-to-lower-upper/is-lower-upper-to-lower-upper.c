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
    // islower (küçük harf ?)
    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "islower fonksiyonu sonucu: ",
    islower('p') ? "p is a " : "p is not a ", "lowercase letter",
    islower('P') ? "P is a " : "P is not a ", "lowercase letter",
    islower('5') ? "5 is a " : "5 is not a ", "lowercase letter",
    islower('!') ? "! is a " : "! is not a ", "lowercase letter");

    // isupper (büyük harf ?)
    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "isupper fonksiyonu sonucu: ",
    isupper('D') ? "D is a " : "D is not a ", "uppercase letter",
    isupper('d') ? "d is a " : "d is not a ", "uppercase letter",
    isupper('8') ? "8 is a " : "8 is not a ", "uppercase letter",
    isupper('$') ? "$ is a " : "$ is not a ", "uppercase letter");

    // tolower (küçük harf yapma)
    printf("%s%c\n%s%c\n%s%c\n%s%c\n\n",
    "U kucuk harfe donusumu ", tolower('U'),
    "7 kucuk harfe donusumu ", tolower('7'),
    "$ kucuk harfe donusumu ", tolower('$'),
    "l kucuk harfe donusumu ", tolower('l'));

    // toupper (büyük harf yapma)
    printf("%s%c\n%s%c\n%s%c\n%s%c\n",
    "U buyuk harfe donusumu ", toupper('U'),
    "7 buyuk harfe donusumu ", toupper('7'),
    "$ buyuk harfe donusumu ", toupper('$'),
    "l buyuk harfe donusumu ", toupper('l'));
}