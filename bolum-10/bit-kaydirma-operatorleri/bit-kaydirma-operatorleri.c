// Slavnem @2024-04-26
// Bit Kaydırma Operatörleri

// Kütüphaneler
#include <stdio.h>

// Fonksiyon Tanımları
void displayBits(unsigned int value);

// main
int main(void)
{
    unsigned int number1 = 960;

    // bitsel sola kaydırmanın gösterilmesi
    puts("\nThe result of left shifting");
    displayBits(number1);
    puts("8 bits positions using the left shift operator << is");
    displayBits(number1 << 8);

    // bitsel sağa kaydırmanın gösterilmesi
    puts("\nThe result of right shifting");
    displayBits(number1);
    puts("8 bits positions using the right shift operator >> is");
    displayBits(number1 >> 8);
}

// bit unsigned int değerinin bitlerinin gösterilmesi
void displayBits(unsigned int value)
{
    unsigned int c; // sayaç

    // displayMask'ın tanımlanması ve bit boyutunun 1 eksiğinin sola kaydırılması
    unsigned int displayMask = 1 << (__CHAR_BIT__ * sizeof(unsigned int)) - 1;

    printf("%5u = ", value);

    // bitler üzerinden döngü
    for(c = 1; c <= (__CHAR_BIT__ * sizeof(unsigned int)); c++)
    {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; // 1 bit sola kaydırmak

        c % 8 == 0 ? putchar(' ') : 0;
    }

    putchar('\n');
}