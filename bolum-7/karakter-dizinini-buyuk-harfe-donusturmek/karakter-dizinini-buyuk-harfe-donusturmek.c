// Bir karakter dizinini sabit olmayan verilere
// sabit olmayan işaretci kullanarak buyuk harflere donusturmek
#include <stdio.h>
#include <ctype.h>

// ++convertToUppercase
void convertToUppercase(char *sPtr);

// +main
int main(void)
{
    char string[] = "nEdEN bU kADaR CiDDiGSiN! Sh4c0"; // char diziyi baslatmak

    printf("Donusturmeden once dizi: %s\n", string);

    convertToUppercase(string);
    printf("Donusturmeden sonra dizi: %s\n", string);
}
// -main

// +convertToUppercase
void convertToUppercase(char *sPtr)
{
    // gecerli karakter '\0' degil ise
    while(*sPtr != '\0')
    {
        // buyuk harfe donustur
        *sPtr = toupper(*sPtr);
        ++sPtr; // sPtr'yi bir sonraki karaktere tasi
    } // while blogu sonu
}
// -convertToUppercase