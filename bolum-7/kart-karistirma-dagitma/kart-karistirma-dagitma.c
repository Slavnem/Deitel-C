// Kart karistirma ve dagitma
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS (SUITS * FACES)

// prototipler
// ++shuffle
void shuffle(unsigned int wDeck[][FACES]); // karistirma wDeck uzerinde degisiklik yapar
// ++deal
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]); // dagitmak diziler uzerinde degisiklik yapmaz

// +main
int main(void)
{
    // suit dizisini yukle
    const char *suit[SUITS] = {"Hearts","Diamonds","Clubs","Spades"};

    // face dizisini yukle
    const char *face[FACES] = {
    "Ace","Deuce","Three","Four",
    "Five","Six","Seven","Eight",
    "Nine","Ten","Jack","Queen","King"};

    // deck dizisini yukle
    unsigned int deck[SUITS][FACES] = {0};

    srand(time(NULL)); // cekirdek rastgele sayi uretici

    shuffle(deck); // desteyi karistir
    deal(deck, face, suit); // desteyi dagit
}
// -main

// deck icerisindeki kartlari karistir
// +shuffle
void shuffle(unsigned int wDeck[][FACES])
{
    size_t row; // satir numarasi
    size_t column; // sutun numarasi
    size_t card; // sayac

    // kartlarin herbiri icin deck yuvasini rastgele olarak sec
    for(card = 1; card < CARDS; ++card)
    {
        // kullanilmayan yuva bulunana kadar rastgele olarak sec
        do
        {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(wDeck[row][column] != 0); // do...while blogu sonu

        // secilen deck yuvasi icerisine kart numarasini yerlestir
        wDeck[row][column] = card;
    } // for blogu sonu
}
// -shuffle

// deck icerisindeki kartlari dagit
// +deal
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
    size_t card; // kart sayacı
    size_t row; // satir sayaci
    size_t column; // sutun sayaci

    // kartlarin herbirini dagit
    for(card = 1; card <= CARDS; ++card)
    {
        // wDeck satirlari boyunca dongu olustur
        for(row = 0; row < SUITS; ++row)
        {
            // gecerli satir icin wDeck sutunlari boyunca dongu olustur
            for(column = 0; column < FACES; ++column)
            {
                // eger slot gecerli karti iceriyorsa karti goruntule
                if(wDeck[row][column] == card)
                {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                    card % 2 == 0 ? '\n' : '\t'); // 2 sutun bicimi
                } // if blogu sonu
            } // for blogu sonu
        } // for blogu sonu
    } // for blogu sonu
}
// -deal