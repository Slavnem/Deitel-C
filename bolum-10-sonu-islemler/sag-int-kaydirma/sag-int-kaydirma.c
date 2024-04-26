// Slavnem @2024-04-26
// Integer Bit Değerini Sağa Kaydırma

// Kütüphaneler
#include <stdio.h>

// Fonksiyon Tanım
void printBit(unsigned int);

// main
int main(void)
{
    unsigned int number; // sayı
    unsigned int bitshift; // bit kaydırma miktarı

    // kullanıcıdan tamsayı değeri almak
    do
    {
        printf("Enter a number between 1 to 99999: ");
        scanf("%d", &number);
    } while(number < 1 || number > 99999);

    // kullanıcıdan bit kaydırma miktarını istemek
    do
    {
        printf("Enter a bit shift number: ");
        scanf("%d", &bitshift);
    } while(bitshift < 1 || bitshift >= (__CHAR_BIT__ * sizeof(number)));

    // normal çıktı ve bit kaydırılmış çıktısı
    puts("Normal Output:");
    printBit(number);

    puts("\nBit Shift Operation Output:");
    printBit(number >> bitshift);
}

// printBit
void printBit(unsigned int value)
{
    size_t i; // sayaç
    unsigned int mask = 1 << (__CHAR_BIT__ * sizeof(value)) - 1; // bit miktarı 

    // değeri çıktı vermek
    printf("%5d = ", value);

    for(i = 1; i <= __CHAR_BIT__ * sizeof(value); ++i)
    {
        putchar(value & mask ? '1' : '0'); // bit çıktısı
        value <<= 1; // 1 bit sola kaydırmak

        // 8 bitten sonra bir boşluk
        i % 8 == 0 ? putchar(' ') : 0;
    }

    putchar('\n'); // satır sonu
}