// ÖZ YİNELİ FİBONACCİ SERİSİ
#include <stdio.h>

unsigned long long int fibonacci(unsigned int n);

int main( void )
{
    unsigned long long int result; // fibonacci değeri
    int number; // kullanıcı tarafından girilen sayı

    // kullanıcıdan tam sayı al
    printf("%s", "Enter an integer: ");
    scanf("%u", &number);

    // girilen sayı 0 veya pozitif değilse
    // istenilen sayı girilene kadar döndür
    while(number < 0)
    {
        // kullanıcıdan tam sayı al
        printf("%s", "Enter an integer: ");
        scanf("%d", &number);
    }

    // kullanıcı tarafından girilen sayı için fibonacci değerini hesapla
    result = fibonacci( number );

    // sonucu göster
    printf("Fibonacci (%u) = %llu\n", number, result);
} // main sonu

// fibonacci fonksiyonunun yinelemeli tanımı
unsigned long long int fibonacci(unsigned int n)
{
    // temel durum
    if(n == 0 || n == 1)
    {
        return n;
    } // if sonu
    else
    {
        // yineleme adımı
        return fibonacci(n-1) + fibonacci(n-2);
    } // else sonu
} // fibonacci fonksiyonu