// ÖZ YİNELEMELİ FAKTÖRİYEL ÖRNEK 1
#include <stdio.h>

unsigned long long int factorial( unsigned int number );

int main( void )
{
    // her bir tekrarlamada, factorial(i) y, hesapla ve sonucu göster
    unsigned int i; // sayaç

    for(i = 0; i <= 21; i++)
    {
        printf("%u! = %llu\n", i, factorial(i));
    } // for sonu
} // main sonu

// factorial fonksiyonunun özyineli tanımı
unsigned long long int factorial( unsigned int number )
{
    // temel durum
    if(number <= 1)
    {
        return 1;
    } // if sonu
    else
    {
        // özyineli adım
        return (number * factorial( number - 1));
    } // else sonu
} // factorial fonksiyonu sonu