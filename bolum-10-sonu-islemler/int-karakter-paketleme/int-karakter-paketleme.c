// Slavnem @2024-05-06
// Integer İçine Karakter Paketleme

// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Fonksiyon Ön Tanımları
void packCharacters(char [sizeof(unsigned int)]);

// main
int main(void)
{
    // karakter dizisi oluşturma ve veri alma
    char* buffer;
    char text[sizeof(unsigned int)];

    // değer al
    printf("Enter a %u characters: ", sizeof(text));
    scanf("%s", buffer);

    // veriyi aktar
    memcpy(text, buffer, sizeof(text));

    // son karakterini \n yani satır sonundan
    // bitiş karakterine \0 çeviriyoruz
    text[sizeof(text)] = '\0';

    // karakter paketleme işlemleri
    packCharacters(text);
}

// packCharacters
void packCharacters(char characters[sizeof(unsigned int)])
{
    // paketleme içinde bit değerlerini gösterecek olan fonksiyon tanımı
    void showBitwise(unsigned int);

    unsigned int values = 0; // karakterleri tutacak olan tamsayı

    // döngü ile işlem
    for(int i = 0; i < sizeof(values); i++)
    {
        // bit kaydırma
        values <<= (i * __CHAR_BIT__);
        
        // değeri kaydetme
        values += (int)(characters[i]);

        // test çıktıları
        printf("value: %c | ", values);
        showBitwise(values);
    }
}

// showBitwise
void showBitwise(unsigned int value)
{
    // geçici tam sayı
    unsigned int itemp = value;
    const unsigned int bitsizevalue = (__CHAR_BIT__ * sizeof(value));

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