// Slavnem @2024-04-25
// Unsigned Int Bit Gösterimi

// Kütüphaneler
#include <stdio.h>

// Fonksiyon tanımları
void displayBits(unsigned int value);

// main
int main(void)
{
    unsigned int x; // kullanıcı girişi tutan değişken

    printf("%s", "Pozitif Tamsayi Giriniz: ");
    scanf("%u", &x);

    displayBits(x);
}

// bir unsigned int değişkeninin bitlerinin gösterilmesi
void displayBits(unsigned int value)
{
    unsigned int c; // sayaç

    // displayMask'ı tanımlama ve 31 biti sola kaydırma
    unsigned int displayMask = 1 << 31;

    printf("%5u = ", value);

    // bitler üzerinden döngü
    for(c = 1; c <= 32; c++)
    {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; // 1 ile değeri sola kaydırma

        // 8 bitten sonraki yerin çıkışı
        if(c % 8 == 0)
        {
            putchar(' ');
        }
    }

    putchar('\n');
}