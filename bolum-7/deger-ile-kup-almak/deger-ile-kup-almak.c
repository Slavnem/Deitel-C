// Deger ile aktarim kullanarak bir degiskenin kupunu almak
#include <stdio.h>

// ++cubeByValue
int cubeByValue(int n); // prototip

// +main
int main(void)
{
    int number = 5; // number ilk atama

    printf("Numaranin orjinal degeri: %d\n", number);

    // number degiskenini deger yolu ile cubeByValue fonksiyonuna aktar
    number = cubeByValue(number);

    printf("Numaranin yeni degeri: %d\n", number);
}
// -main

// +cubeByValue
int cubeByValue(int n)
{
    return n * n * n; // n yerel degiskeninin kupunu al ve sonucu dondur
}
// -cubeByValue