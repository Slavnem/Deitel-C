// Slavnem @2024-04-25
// Bit And &, Bit Or |, Bit Xor ^ ve Bit Complement Kullanımı

// Kütüphaneler
#include <stdio.h>

// Fonksiyon Tanımlar
void displayBits(unsigned int value);

// main
int main(void)
{
    unsigned int number1;
    unsigned int number2;
    unsigned int mask;
    unsigned int setBits;

    // bitsel AND (&) göstermek
    number1 = 65535;
    mask = 1;
    
    puts("The result of combining the following");

    displayBits(number1);
    displayBits(mask);

    puts("Using the bitwise AND operator & is");

    // bitsel inclusive OR (|) gösterilmesi
    number1 = 15;
    setBits = 241;

    puts("\nThe result of combining the following");

    displayBits(number1);
    displayBits(setBits);

    puts("using the bitwise inclusive OR operator | is");

    displayBits(number1 | setBits);

    // bitsel XOR yani exclusive OR (^) gösterilmesi
    number1 = 139;
    number2 = 199;

    puts("\nThe result of combining the following");

    displayBits(number1);
    displayBits(number2);

    puts("using the bitwise exclusive OR operator ^ is");

    displayBits(number1 ^ number2);

    // bitsel complement (~)'in gösterilmesi
    number1 = 21845;

    puts("\nThe one's complement of");

    displayBits(number1);

    puts("is");

    displayBits(~number1);    
}

// displayBits
void displayBits(unsigned int value)
{
    unsigned int c; // sayaç

    // displayMask'ı bildirme ve 31 biti sola kaydırma
    unsigned int displayMask = 1 << (__CHAR_BIT__ * sizeof(unsigned int)) - 1;

    printf("%5u = ", value);

    // bitlerin döngüsü
    for(c = 1; c <= (__CHAR_BIT__ * sizeof(unsigned int)); c++)
    {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; // 1 ile değeri sola kaydırmak

        if(c % 8 == 0)
        {
            // 8 bitlikten sonra boşluk yazdırma
            putchar(' ');
        }
    }

    putchar('\n');
}