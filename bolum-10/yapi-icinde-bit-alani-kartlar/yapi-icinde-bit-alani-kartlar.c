// Slavnem @2024-04-26
// Yapı İçinde Bit Alanlarını Kartlar İle Temsil Etme

// Kütüphaneler
#include <stdio.h>
#define CARDS 52

// bitCard yapısı bit alanlarıyla tanımlanıyor
struct bitCard {
    unsigned int face : 4; // 4 bit; 0-15
    unsigned int suit : 2; // 2 bit; 0-3
    unsigned int color : 1; // 1 bit; 0-1
};

// Tip İsimlendirmesi
typedef struct bitCard Card; // bitCard yapısı için yeni tür adı

// Fonksiyon Tanımlamaları
void fillDeck(Card* const wDeck);
void deal(const Card* const wDeck);

// main
int main(void)
{
    Card deck[CARDS]; // kartlar dizisi oluşturuluyor

    fillDeck(deck);
    deal(deck);
}

// Kartlar başlatılıyor
void fillDeck(Card* const wDeck)
{
    size_t i; // sayaç

    // wDeck sayesinde döngüye girer
    for(i = 0; i < CARDS; i++)
    {
        wDeck[i].face = i % (CARDS / 4);
        wDeck[i].suit = i / (CARDS / 4);
        wDeck[i].color = i / (CARDS / 2);
    }
}

// kart çıktıları 2 sütun biçiminde olmuştur
// kartlar 0-25 arası sayılar ki (sütun 1) de belirtilmiştir
// 26-51 arası kartlar k2 (sütun 2) de belirtilmiştir
void deal(const Card* const wDeck)
{
    size_t k1; // subscripts 0-25
    size_t k2; // subscripts 26-51

    // wDeck sayesinde döngüye girer
    for(k1 = 0, k2 = k1 + 26; k1 < CARDS / 2; ++k1, +k2)
    {
        printf("Card:%3d Suit:%2d Color:%2d ", wDeck[k1].face, wDeck[k1].suit, wDeck[k1].color);
        printf("Card:%3d Suit:%2d Color:%2d\n", wDeck[k2].face, wDeck[k2].suit, wDeck[k2].color);
    }
}