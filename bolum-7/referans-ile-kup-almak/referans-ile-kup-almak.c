// Isaretci bir arguman ile referans ile aktarim kullanarak bir degiskenin kupunu alma
#include <stdio.h>

// ++cubeByReference
void cubeByReference(int *nPtr); // fonksiyon prototipi

// +main
int main(void)
{
    int number = 5; // number ilk deger atama

    printf("Numaranin orjinal degeri: %d\n", number);

    // degisken adresini cubeByReference aktar
    cubeByReference(&number);

    printf("Numaranin yeni degeri: %d\n", number);
}
// -main

// +cubeByReference
void cubeByReference(int *nPtr)
{
    *nPtr = *nPtr * *nPtr * *nPtr; // *nPtr kupunu al
}
// -cubeByReference