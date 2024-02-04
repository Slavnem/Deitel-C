/*
    Yazan: Slavnem
    Dil: C
*/

// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    char s1[20] = "Happy"; // s1 karakter dizisine başlangıç değeri atama
    char s2[] = "New Year"; // s1 karakter dizisine başlangıç değeri atama
    char s3[40] = ""; // s3 karakter dizisine boş değer atama

    printf("s1 = %s\ns2 = %s\n", s1, s2);

    // s2 ile s1 dizisini birleştirme
    printf("strcat(s1, s2) = %s\n", strcat(s1, s2));

    // s1 dizisinin ilk 6 karakterinin s3 ile birleştirilmesi,
    // son karakterden sonra '\0' konulması
    printf("strncat(s3, s1, 6) = %s\n", strncat(s3, s1, 6));

    // s1 ile s3 dizisinin birleştirilmesi
    printf("strcat(s3, s1) = %s\n", strcat(s3, s1));
}