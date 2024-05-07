// Slavnem @2024-05-07
// Unsigned Integer İçine Karakter Paketleme ve Açma

// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Ön Tanımlamalar
#define SIZE_UINT_BYTE (sizeof(unsigned int))
#define SIZE_BIT (__CHAR_BIT__)

// Fonksiyon Ön Tanımları
void packCharacters(char[]);

// main
int main(void)
{
    // karakter dizisi oluşturma ve veri alma
    char text[SIZE_UINT_BYTE + 1];

    // değer al
    printf("Enter a %u characters: ", (sizeof(text) - 1));
    fgets(text, sizeof(text), stdin);

    // karakter paketleme işlemleri
    packCharacters(text);
}

// packCharacters
void packCharacters(char characters[])
{
    // paketleme içinde bit değerlerini gösterecek olan fonksiyon tanımı
    void showBitwise(unsigned int);

    unsigned int values = 0; // karakterleri tutacak olan tamsayı

    // döngü ile işlem
    for(int i = 0; i < sizeof(values); i++)
    {
        // değeri kaydetme
        values |= (unsigned int)(characters[i]) << (i * SIZE_BIT);

        // test çıktıları
        printf("value: %c | ", (char)(values >> (i * SIZE_BIT)));
        showBitwise(values);
    }
}

// showBitwise
void showBitwise(unsigned int value)
{
    // geçici tam sayı
    unsigned int itemp = value;
    const unsigned int bitsizevalue = (SIZE_BIT * sizeof(value));

    // döngü ile bitleri göstermek
    for(int bit = 1; bit <= bitsizevalue; bit++)
    {
        putchar(itemp & value ? '1' : '0'); // bit değeri
        (bit % 8 == 0) ? putchar(' ') : 0; // her 8'bit arası 1 boşluk

        // bir sonraki adrese geçme
        itemp <<= 1;
    }

    // boş satır
    putchar('\n');
}