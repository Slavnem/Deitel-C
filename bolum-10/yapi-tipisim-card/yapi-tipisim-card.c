// Slavnem @2024-04-24
// Yapı (Struct), Tip İsim (Typedef), Card

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ön tanımlamalar
#define CARDS 52
#define FACES 13

// card yapısının tanımlanması
struct card
{
    const char* face; // face işaretçisi tanımlanıyor
    const char* suit; // suit işaretçisi tanımlanıyor
};

typedef struct card Card; // card yapısı için yeni tip ismi

// prototipler
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]);
void shuffle(Card* const wDeck);
void deal(const Card* const wDeck);

// main
int main(void)
{
    Card deck[CARDS]; // Cards dizisi tanımla

    // işaretçi dizilerinin ilklendirilmesi
    const char* face[] =
    {
        "Ace", "Deuce", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Jack", "Queen", "King"
    };

    // işaretçi dizilerinin ilklendirilmesi
    const char* suit[] =
    {
        "Hearts", "Diamonds", "Clubs", "Spades"
    };

    // rastgele
    srand(time(NULL));

    fillDeck(deck, face, suit); // desteye kartları yükle
    shuffle(deck); // Cardlar rastgele yerleştir
    deal(deck); /// 52 Card'ın tümünü dağıt
}

// Card yapılarının içine stringler yerleştiriliyor
void fillDeck(Card * const wDeck, const char* wFace[], const char* wSuit[])
{
    size_t i; // sayaç

    // kartları yükle
    for(i = 0; i < CARDS; i++)
    {
        wDeck[i].face = wFace[i % FACES];
        wDeck[i].suit = wSuit[i / FACES];
    }
}

// Kartları karıştır
void shuffle(Card* const wDeck)
{
    size_t i; // sayaç
    size_t j; // değişken 0 - 51 arasında rastgele değer tutuyor
    Card temp; // Cardları değiştirnmek için geçici yapı tanımlanıyor

    // wDeck üzerinden döngü rastgele olarak cardları değiştiriyor
    for(i = 0; i < CARDS; i++)
    {
        j = rand() % CARDS; // j'ye rastgele değer vermek 0-51

        // geçici Card yapısını kopyalamak
        temp = wDeck[i];

        // düzenli sıra ile rastgele sıradaki desteyi değiştirmek
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}

// Kartları dağıt
void deal(const Card* const wDeck)
{
    size_t i; // sayaç

    // wDeck üzerinden döngü
    for(i = 0; i < CARDS; i++)
    {
        printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? " " : "\n");
    }
}