// Slavnem @2024-04-26
// Integer Bit Değerini Sağa Kaydırma

// Kütüphaneler
#include <stdio.h>

// Yapı tanımı
typedef struct
{
    unsigned int n : 4; // 4 bit 0-15
    unsigned int: 28; // bellek veri hizalama
} Type;

// Fonksiyon Tanım
void printBit(unsigned int);

// main
int main(void)
{
    Type NumType; // sayı
    unsigned int bitshift; // bit kaydırma miktarı

    // 4 bitlik sayı verme
    NumType.n = 13;

    // kullanıcıdan bit kaydırma miktarını istemek
    do
    {
        printf("Enter a bit shift number: ");
        scanf("%d", &bitshift);
    } while(bitshift < 1 || bitshift > 4);

    // normal çıktı ve bit kaydırılmış çıktısı
    puts("Normal Output:");
    printBit(NumType.n);

    puts("\nBit Shift Operation Output:");
    printBit(NumType.n >> bitshift);
}

// printBit
void printBit(unsigned int value)
{
    size_t i; // sayaç
    unsigned int mask = 1 << 3; // bit miktarı 

    // değeri çıktı vermek
    printf("%5d = ", value);

    for(i = 1; i <= 4; ++i)
    {
        putchar(value & mask ? '1' : '0'); // bit çıktısı
        value <<= 1; // 1 bit sola kaydırmak

        // 8 bitten sonra bir boşluk
        i % 8 == 0 ? putchar(' ') : 0;
    }

    putchar('\n'); // satır sonu
}