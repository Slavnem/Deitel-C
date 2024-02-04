#include <stdio.h>

int main( void )
{
    char karakter;

    printf("Sadece ilk harf gecerlidir!\nBir karakter giriniz: ");
    scanf("%c", &karakter);
    printf("Girilen karakter tamsayi degeri = %d\n", (int)(karakter));
}
