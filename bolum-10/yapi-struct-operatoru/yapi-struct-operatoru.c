// Slavnem @2024-04-23
// Yapı (Struct) Operatörü

// Kütüphaneler
#include <stdio.h>

// card yapısının tanımlanması
struct card
{
    char* face; // face işaretçisi tanımlama
    char* suit; // suit işaretçisi tanımlama
};

// main
int main(void)
{
    struct card aCard; // bir card yapısının tanımlanması
    struct card* cardPtr; // bir cad yapısına bir işaretçi tanımlama

    // aCard içine string yerleştirme
    aCard.face = "Ace";
    aCard.suit = "Spades";

    cardPtr = &aCard; // aCard'dan, cardPtr'nin adresini işaretleme

    printf("%s%s%s\n%s%s%s\n%s%s%s\n",
        aCard.face, " of ", aCard.suit,
        cardPtr->face, " of ", cardPtr->suit,
        (*cardPtr).face, " of ", (*cardPtr).suit);
}